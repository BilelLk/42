/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:52:14 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/11 19:00:51 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	print_err_cmd(char *cmd, t_pipe *pipex);

// Parse input parameters to find the command to execute
char	*get_cmd(char **path, char *cmd, t_pipe *pipex)
{
	char	*tmp;
	char	*command;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		if (!tmp)
			return (NULL);
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!command)
			return (NULL);
		if (access(command, F_OK | X_OK) == 0)
			return (command);
		free(command);
		path++;
	}
	print_err_cmd(cmd, pipex);
	return (NULL);
}

static void	print_err_cmd(char *cmd, t_pipe *pipex)
{
	if (!check_right(pipex))
	{
		write(2, cmd, ft_strlen(cmd));
		ft_putendl_fd(": command not found", 2);
	}
}

int	pipex_split_parsing(t_pipe *pipex, int i)
{
	pipex->split_parsing = ft_split(pipex->argv[2 + pipex->index], ' ');
	if (!pipex->split_parsing)
		ft_exit(pipex, "check_path split failed");
	if (!pipex->split_parsing[i])
	{
		if (!check_right(pipex))
		{
			ft_putendl_fd(": command not found", 2);
			return (-1);
		}
	}
	return (0);
}
