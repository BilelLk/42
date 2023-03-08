/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:54:37 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/08 13:34:34 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_pipex(t_pipe *pipex, int argc, char **argv, char **env);
static void	get_file(t_pipe *p, char **argv, int argc);
static void	ft_error_argc(void);
static void	print_err_env_null(int argc, char **argv, t_pipe *pipex);

int	main(int argc, char **argv, char **env)
{
	t_pipe	pipex;

	ft_bzero(&pipex, sizeof(t_pipe));
	if (argc != 5)
		ft_error_argc();
	init_pipex(&pipex, argc, argv, env);
	create_pipes(&pipex);
	get_file(&pipex, argv, argc);
	process(&pipex, env);
	ft_close_everything(&pipex);
	while (waitpid(-1, NULL, 0) != -1)
		;
	parent_free(&pipex);
	return (0);
}

// Open the files
static void	get_file(t_pipe *pipex, char **argv, int argc)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		perror(argv[1]);
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1)
		perror(argv[argc - 1]);
}

// Init Struct
static void	init_pipex(t_pipe *pipex, int argc, char **argv, char **env)
{
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->nb_cmd = argc - 3;
	pipex->pipe = ft_calloc(argc - 3, sizeof(int *));
	pipex->pid = ft_calloc(pipex->nb_cmd, sizeof(int));
	if (!pipex->pipe || !pipex->pid)
		ft_exit(pipex, NULL);
	pipex->env_path = find_path(env);
	if (pipex->env_path != NULL)
	{
		pipex->cmd_paths = ft_split(pipex->env_path, ':');
		if (!pipex->cmd_paths)
			ft_exit(pipex, NULL);
	}
	else
		print_err_env_null(argc, argv, pipex);
}

static void	ft_error_argc(void)
{
	ft_putendl_fd(ARG_ERROR, 2);
	ft_putendl_fd(PIPE_MODEL, 2);
	exit(1);
}

static void	print_err_env_null(int argc, char **argv, t_pipe *pipex)
{
	int	i;

	i = 0;
	while (i != argc - 3)
	{
		write(2, argv[i + 2], ft_strlen(argv[i + 2]));
		ft_putendl_fd(": command not found", 2);
		i++;
	}
	pipex->cmd_paths = NULL;
}
