/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:57:13 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/11 17:23:52 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// Free all allocation in t_pipeex
// Close input and ouput files
void	parent_free(t_pipe *pipex)
{
	int	i;

	i = 0;
	if (pipex->cmd_paths)
		ft_free_split(pipex->cmd_paths);
	if (pipex->cmd_args)
		ft_free_split(pipex->cmd_args);
	if (pipex->cmd)
		free(pipex->cmd);
	if (pipex->pipe)
	{
		i = 0;
		while (i < pipex->nb_cmd - 1)
		{
			free(pipex->pipe[i]);
			i++;
		}
		free(pipex->pipe);
	}
	if (pipex->pid)
		free(pipex->pid);
}

void	ft_exit(t_pipe *pipex, char *str)
{
	ft_close_everything(pipex);
	parent_free(pipex);
	if (str)
		ft_putendl_fd(str, 2);
	exit(1);
}

void	ft_close(int *fd)
{
	if (*fd > 0)
		close(*fd);
	*fd = 0;
}

void	ft_close_everything(t_pipe *pipex)
{
	int	i;

	i = 0;
	ft_close(&pipex->infile);
	ft_close(&pipex->outfile);
	if (pipex->pipe)
	{
		while (i < pipex->nb_cmd - 1)
		{
			if (pipex->pipe[i])
			{
				ft_close(&pipex->pipe[i][0]);
				ft_close(&pipex->pipe[i][1]);
			}
			i++;
		}
	}
}

void	ft_free_split(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}
