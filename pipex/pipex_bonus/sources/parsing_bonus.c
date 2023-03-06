/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:56:36 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/06 20:22:58 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	check_cmd_is_not_found(t_pipe *pipex);
static int	check_dot_filename(t_pipe *pipex);
static int	check_dot_slash_none_filename(t_pipe *pipex);
static int	check_path(t_pipe *pipex);

int	parsing_error_cmd(t_pipe *pipex)
{
	if (check_cmd_is_not_found(pipex) == -1)
		return (-1);
	if (check_dot_filename(pipex) == -1)
		return (-1);
	if (check_dot_slash_none_filename(pipex) == -1)
		return (-1);
	if (check_path(pipex) == -1)
		return (-1);
	return (0);
}

static int	check_cmd_is_not_found(t_pipe *pipex)
{
	if (pipex->argv[2 + pipex->index][0] == 0)
	{
		if (pipex->err_infile == -1 && pipex->err_outfile == -1)
			if ((2 + pipex->index) > 2 && (2 + pipex->index) < pipex->argc - 2)
				ft_putendl_fd(": command not found", 2);
		if (pipex->err_infile == -1 && pipex->err_outfile == 0)
			if ((2 + pipex->index) > 2)
				ft_putendl_fd(": command not found", 2);
		if (pipex->err_infile == 0 && pipex->err_outfile == -1)
			if ((2 + pipex->index) < pipex->argc - 2)
				ft_putendl_fd(": command not found", 2);
		if (pipex->err_infile == 0 && pipex->err_outfile == 0)
			ft_putendl_fd(": command not found", 2);
		return (-1);
	}
	return (0);
}

static int	check_dot_filename(t_pipe *pipex)
{
	if (pipex->argv[2 + pipex->index][0] == '.' && !pipex->argv[2 + pipex->index][1])
	{
		ft_putendl_fd(".: filename argument required", 2);
		ft_putendl_fd(".: usage: . filename [arguments]", 2);
		return (-1);
	}
	return (0);
}

static int	check_dot_slash_none_filename(t_pipe *pipex)
{
	if (pipex->argv[2 + pipex->index][0] == '.' && 	pipex->argv[2 + pipex->index][1] == '/' && !ft_isalnum(pipex->argv[2 + pipex->index][2]))
	{
		ft_putendl_fd("./ : Is a directory", 2);
		return (-1);
	}
	else if ((pipex->argv[2 + pipex->index][0] == '/' && !ft_isalnum(pipex->argv[2 + pipex->index][1])))
	{
		ft_putendl_fd("/ : Is a directory", 2);
		return (-1);
	}
	return (0);
}

static int	check_path(t_pipe *pipex)
{
	int	fd;

	if (ft_strrchr(pipex->argv[2 + pipex->index], '/'))
	{
		fd = open(pipex->argv[2 + pipex->index], O_RDONLY);
		if (fd == -1 || access(pipex->argv[2 + pipex->index], F_OK | X_OK))
		{
			perror(pipex->argv[2 + pipex->index]);
			return (-1);
		}
	}
	return (0);
}
