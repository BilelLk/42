/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:56:36 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/05 14:02:41 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	check_cmd_is_not_found(int argc, char **argv, t_pipe *pipex);
static void	check_dot_filename(t_pipe *pipex, char **argv);
static void	check_dot_slash_none_filename(t_pipe *pipex, char **argv);
static void	check_path(t_pipe *pipex, char **argv);

void	parsing_error_cmd(t_pipe *pipex, int argc, char **argv)
{
	check_cmd_is_not_found(argc, argv, pipex);
	check_dot_filename(pipex, argv);
	check_dot_slash_none_filename(pipex, argv);
	check_path(pipex, argv);
}

static void	check_cmd_is_not_found(int argc, char **argv, t_pipe *pipex)
{
	if (argv[2 + pipex->index][0] == 0)
	{
		if (pipex->err_infile == -1 && pipex->err_outfile == -1)
			if ((2 + pipex->index) > 2 && (2 + pipex->index) < argc - 2)
				ft_putendl_fd(": command not found", 2);
		if (pipex->err_infile == -1 && pipex->err_outfile == 0)
			if ((2 + pipex->index) > 2)
				ft_putendl_fd(": command not found", 2);
		if (pipex->err_infile == 0 && pipex->err_outfile == -1)
			if ((2 + pipex->index) < argc - 2)
				ft_putendl_fd(": command not found", 2);
		if (pipex->err_infile == 0 && pipex->err_outfile == 0)
			ft_putendl_fd(": command not found", 2);
		ft_exit(pipex, NULL, PARSING, NO);
	}
}

static void	check_dot_filename(t_pipe *pipex, char **argv)
{
	if (argv[2 + pipex->index][0] == '.' && !argv[2 + pipex->index][1])
	{
		ft_putendl_fd(".: filename argument required", 2);
		ft_putendl_fd(".: usage: . filename [arguments]", 2);
		ft_exit(pipex, NULL, PARSING, NO);
	}
}

static void	check_dot_slash_none_filename(t_pipe *pipex, char **argv)
{
	if (argv[2 + pipex->index][0] == '.' && argv[2 + pipex->index][1] == '/' && \
	!ft_isalnum(argv[2 + pipex->index][2]))
	{
		ft_putendl_fd("./ : is a directory", 2);
		ft_exit(pipex, NULL, PARSING, NO);
	}
	else if ((argv[2 + pipex->index][0] == '/' && \
	!ft_isalnum(argv[2 + pipex->index][1])))
	{
		ft_putendl_fd("/ : is a directory", 2);
		ft_exit(pipex, NULL, PARSING, NO);
	}
}

static void	check_path(t_pipe *pipex, char **argv)
{
	int	fd;

	if (ft_strrchr(argv[2 + pipex->index], '/'))
	{
		fd = open(argv[2 + pipex->index], O_RDONLY);
		if (fd == -1 || access(argv[2 + pipex->index], F_OK | X_OK))
			ft_exit(pipex, argv[2 + pipex->index], PARSING, YES);
	}
}
