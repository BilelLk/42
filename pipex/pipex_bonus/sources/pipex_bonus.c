/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:54:37 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/06 20:21:38 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	init_pipex(t_pipe *pipex, int argc, char **argv, char **env);
static void	get_file(t_pipe *p, char **argv, int argc);
static void	ft_error_argc(void);

int	main(int argc, char **argv, char **env)
{
	t_pipe	pipex;

	ft_bzero(&pipex, sizeof(t_pipe));
	if (argc < 5)
		ft_error_argc();
	get_file(&pipex, argv, argc);
	init_pipex(&pipex, argc, argv, env);
	create_pipes(&pipex);
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
	pipex->err_outfile = 0;
	pipex->err_infile = 0;
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		pipex->err_infile = -1;
		perror(argv[1]);
	}
	pipex->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1)
	{
		pipex->err_outfile = -1;
		perror(argv[argc - 1]);
	}
}

// Init Struct
static void	init_pipex(t_pipe *pipex, int argc, char **argv, char **env)
{
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->nb_cmd = argc - 3;
	pipex->pipe = malloc(sizeof(int *) * (argc - 3));
	pipex->pid = malloc(sizeof(int) * pipex->nb_cmd);
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
		pipex->cmd_paths = NULL;
}

static void	ft_error_argc(void)
{
	ft_putendl_fd(ARG_ERROR, 2);
	ft_putendl_fd(PIPE_MODEL, 2);
	exit(1);
}
