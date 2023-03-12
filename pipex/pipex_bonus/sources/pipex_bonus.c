/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:54:37 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/11 18:47:52 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	init_pipex(t_pipe *pipex, int argc, char **argv, char **env);
static void	get_file(t_pipe *p, char **argv, int argc);
static void	print_err_env_null(int argc, char **argv, t_pipe *pipex);
static void	ft_check_arg(int argc, char **argv, t_pipe *pipex);

int	main(int argc, char **argv, char **env)
{
	t_pipe	pipex;

	ft_bzero(&pipex, sizeof(t_pipe));
	ft_check_arg(argc, argv, &pipex);
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

static void	ft_check_arg(int argc, char **argv, t_pipe *pipex)
{
	if (argc > 1)
	{
		if (argv[1][0] == 'h' && argv[1][1] == 'e' && \
		argv[1][2] == 'r' && argv[1][3] == 'e' && \
		argv[1][4] == '_' && argv[1][5] == 'd' && \
		argv[1][6] == 'o' && argv[1][7] == 'c' && !argv[1][8])
			pipex->here_doc = 1;
	}
	if (argc < 5 + pipex->here_doc)
		ft_error_argc(pipex);
}

// Init Struct
static void	init_pipex(t_pipe *pipex, int argc, char **argv, char **env)
{
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->nb_cmd = argc - (3 + pipex->here_doc);
	pipex->pipe = ft_calloc((argc - (3 + pipex->here_doc)), sizeof(int *));
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

// Open the files
static void	get_file(t_pipe *pipex, char **argv, int argc)
{
	if (!pipex->here_doc)
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile == -1)
			perror(argv[1]);
		pipex->outfile = open(argv[argc - 1], \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else
	{
		pipex_here_doc(pipex, argv[2]);
		pipex->outfile = open(argv[argc - 1], \
		O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	if (pipex->outfile == -1)
		perror(argv[argc - 1]);
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
