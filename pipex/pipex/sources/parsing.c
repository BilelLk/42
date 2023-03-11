/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:56:36 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/11 17:20:23 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_cmd_is_not_found(t_pipe *pipex, char *cmd);
static int	check_dot_filename(t_pipe *pipex, char *cmd);
static int	check_dot_slash_none_filename(t_pipe *pipex, char *cmd);
static int	check_path(t_pipe *pipex, char *cmd);

int	parsing_error_cmd(t_pipe *pipex)
{
	int		i;

	i = 0;
	pipex_split_parsing(pipex, i);
	while (pipex->split_parsing[i])
	{
		if (check_cmd_is_not_found(pipex, pipex->split_parsing[i]) == -1)
			return (ft_free_split(pipex->split_parsing), \
			pipex->argv[2 + pipex->index] = NULL, -1);
		if (check_dot_filename(pipex, pipex->split_parsing[i]) == -1)
			return (ft_free_split(pipex->split_parsing), \
			pipex->argv[2 + pipex->index] = NULL, -1);
		if (check_dot_slash_none_filename(pipex, pipex->split_parsing[i]) == -1)
			return (ft_free_split(pipex->split_parsing), \
			pipex->argv[2 + pipex->index] = NULL, -1);
		if (check_path(pipex, pipex->split_parsing[i]) == -1)
			return (ft_free_split(pipex->split_parsing), \
			pipex->argv[2 + pipex->index] = NULL, -1);
		i++;
	}
	ft_free_split(pipex->split_parsing);
	return (0);
}

static int	check_cmd_is_not_found(t_pipe *pipex, char *cmd)
{
	if (cmd[0] == '.' && ft_isalnum(cmd[1]))
	{
		if (!check_right(pipex))
		{
			write(2, cmd, \
			ft_strlen(cmd));
			ft_putendl_fd(": command not found", 2);
		}
		return (-1);
	}
	return (0);
}

static int	check_dot_filename(t_pipe *pipex, char *cmd)
{
	if (cmd[0] == '.' && !cmd[1])
	{
		if (!check_right(pipex))
		{
			ft_putendl_fd(".: filename argument required", 2);
			ft_putendl_fd(".: usage: . filename [arguments]", 2);
		}
		return (-1);
	}
	return (0);
}

static int	check_dot_slash_none_filename(t_pipe *pipex, char *cmd)
{
	if (cmd[0] == '.' && cmd[1] == '/' && !ft_isalnum(cmd[2]))
	{
		if (!check_right(pipex))
			ft_putendl_fd("./ : Is a directory", 2);
		return (-1);
	}
	else if ((cmd[0] == '/' && !ft_isalnum(cmd[1])))
	{
		if (!check_right(pipex))
			ft_putendl_fd("/ : Is a directory", 2);
		return (-1);
	}
	return (0);
}

static int	check_path(t_pipe *pipex, char *cmd)
{
	int		fd;

	if (ft_strrchr(cmd, '/'))
	{
		if (!check_right(pipex))
		{
			fd = open(cmd, O_RDONLY);
			if (fd == -1 || access(cmd, F_OK))
			{
				perror(cmd);
				if (fd != -1)
					close (fd);
				return (-1);
			}
			if (fd != -1)
				close (fd);
		}
	}
	return (0);
}
