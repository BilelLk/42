/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:57:13 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/05 14:02:41 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error_argc(void)
{
	ft_putendl_fd(ARG_ERROR, 2);
	ft_putendl_fd(PIPE_MODEL, 2);
	exit(1);
}

// Free all allocation in t_pipeex
// Close input and ouput files
void	parent_free(t_pipe *pipex)
{
	int	i;

	i = 0;
	if (pipex->cmd_paths)
	{
		while (pipex->cmd_paths[i])
		{
			free(pipex->cmd_paths[i]);
			i++;
		}
		free(pipex->cmd_paths);
	}
	if (pipex->pipe)
	{
		i = 0;
		while (i < pipex->nb_cmd)
		{
			free(pipex->pipe[i]);
			i++;
		}
		free(pipex->pipe);
	}
}

void	ft_exit(t_pipe *pipex, char *str, t_error e_type, t_print print)
{
	if (print == YES)
		perror(str);
	if (e_type == FILES)
	{
		close_pipes(pipex);
		parent_free(pipex);
		exit(1);
	}
	else if (e_type == FORK)
	{
		close_pipes(pipex);
		parent_free(pipex);
		exit(1);
	}
	else if (e_type == PARSING)
	{
		close_pipes(pipex);
		if (pipex->infile > 0 && pipex->err_infile != -1)
			close(pipex->infile);
		if (pipex->outfile > 0 && pipex->err_outfile != -1)
			close(pipex->outfile);
		free(pipex->cmd);
		parent_free(pipex);
		pipex->cmd = NULL;
		pipex->cmd_args = NULL;
		pipex->env_path = NULL;
		exit(1);
	}
}
