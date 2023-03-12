/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:55:56 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/12 15:31:52 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	child(t_pipe *pipex, char **env);
static int	manage_dup(t_pipe *pipex);
static int	dup2_double(int in, int out);
static int	pipex_cmd(t_pipe *pipex);

void	process(t_pipe *pipex, char **env)
{
	pipex->index = 0;
	while (pipex->index < pipex->nb_cmd)
	{
		parsing_error_cmd(pipex);
		if (pipex->argv[2 + pipex->index + pipex->here_doc])
			child(pipex, env);
		pipex->index++;
	}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

// Create a child process using fork to execute command
static void	child(t_pipe *pipex, char **env)
{
	pipex->pid[pipex->index] = fork();
	if (pipex->pid[pipex->index] == -1)
		ft_exit(pipex, FORK_ERROR);
	if (pipex->pid[pipex->index] == 0)
	{
		pipex->cmd_args = ft_split(pipex->argv[2 + pipex->index + \
			pipex->here_doc], ' ');
		if (!pipex->cmd_args)
			return (ft_close_everything(pipex), \
			parent_free(pipex), exit(1));
		if (pipex_cmd(pipex) == -1)
			return (ft_close_everything(pipex), \
			parent_free(pipex), exit(1));
		if (manage_dup(pipex) == -1)
			return (ft_close_everything(pipex), \
			parent_free(pipex), exit(1));
		ft_close_everything(pipex);
		if (execve(pipex->cmd, pipex->cmd_args, env) == -1)
			perror(pipex->cmd);
	}
}

static int	pipex_cmd(t_pipe *pipex)
{
	if (ft_strrchr(pipex->cmd_args[0], '/') == 0)
	{
		if (!pipex->env_path)
			return (-1);
		pipex->cmd = get_cmd(pipex->cmd_paths, \
		pipex->cmd_args[0], pipex);
	}
	else
		pipex->cmd = pipex->cmd_args[0];
	if (!pipex->cmd)
		return (-1);
	return (0);
}

// Manage the dup2 based on the position of the command
static int	manage_dup(t_pipe *pipex)
{
	if (!pipex->index && !pipex->here_doc)
	{
		if (pipex->infile == -1)
			return (-1);
		if (dup2_double(pipex->infile, pipex->pipe[0][1]) == -1)
			return (-1);
	}
	else if (!pipex->index && pipex->here_doc && dup2(pipex->pipe[0][1], \
		STDOUT_FILENO) == -1)
		return (-1);
	else if (pipex->index == pipex->nb_cmd - 1)
	{
		if (pipex->outfile == -1)
			return (-1);
		if (dup2_double(pipex->pipe[pipex->index - 1][0], pipex->outfile) == -1)
			return (-1);
	}
	else if (pipex->index)
		if (dup2_double(pipex->pipe[pipex->index - 1][0],
			pipex->pipe[pipex->index][1]) == -1)
			return (-1);
	return (0);
}

// Duplicate STDIN and STDOUT to the desired fds
static int	dup2_double(int in, int out)
{
	if (dup2(in, STDIN_FILENO) == -1)
		return (-1);
	if (dup2(out, STDOUT_FILENO) == -1)
		return (-1);
	return (0);
}
