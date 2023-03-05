/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:54:37 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/05 14:02:41 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	init_pipeex(t_pipe *pipex, int argc, char **env);
static int	get_file(t_pipe *p, char **argv, int argc);

int	main(int argc, char **argv, char **env)
{
	t_pipe	pipex;

	ft_bzero(&pipex, sizeof(t_pipe));
	if (argc < 5)
		ft_error_argc();
	get_file(&pipex, argv, argc);
	init_pipeex(&pipex, argc, env);
	create_pipes(&pipex);
	process(&pipex, argc, argv, env);
	close_pipes(&pipex);
	close(pipex.infile);
	close(pipex.outfile);
	while (waitpid(-1, NULL, 0) > 0)
		;
	parent_free(&pipex);
	return (0);
}

// Open the files
static int	get_file(t_pipe *pipex, char **argv, int argc)
{
	pipex->err_outfile = 0;
	pipex->err_infile = 0;
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		pipex->err_infile = -1;
		perror(argv[1]);
		pipex->infile = open("/dev/null", O_RDONLY);
		if (pipex->infile == -1)
			exit(1);
	}
	pipex->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1)
	{
		pipex->err_outfile = -1;
		ft_exit(pipex, argv[argc - 1], NONE, YES);
		return (1);
	}
	return (1);
}

// Init Struct
static void	init_pipeex(t_pipe *pipex, int argc, char **env)
{
	pipex->nb_cmd = argc - 3;
	pipex->pipe = malloc(sizeof(int *) * (argc - 3));
	if (!pipex->pipe)
		ft_exit(pipex, NULL, FILES, NO);
	pipex->env_path = find_path(env);
	if (pipex->env_path != NULL)
	{
		pipex->cmd_paths = ft_split(pipex->env_path, ':');
		if (!pipex->cmd_paths)
			ft_exit(pipex, NULL, FILES, NO);
	}
	else
		pipex->cmd_paths = NULL;
}
