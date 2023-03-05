/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:55:56 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/05 14:02:41 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	child(t_pipe *pipex, int argc, char **argv, char **env);
static void	manage_dup(t_pipe *pipex);
static int	dup2_double(int in, int out);
static char	*get_cmd(char **path, char *cmd);

void	process(t_pipe *pipex, int argc, char **argv, char **env)
{
	pipex->index = -1;
	while (++(pipex->index) < pipex->nb_cmd)
		child(pipex, argc, argv, env);
}

// Create a child process using fork to execute command
static void	child(t_pipe *pipex, int argc, char **argv, char **env)
{
	pipex->pid = fork();
	if (pipex->pid == -1)
		ft_exit(pipex, FORK_ERROR, FORK, YES);
	if (pipex->pid == 0)
	{
		parsing_error_cmd(pipex, argc, argv);
		manage_dup(pipex);
		close_pipes(pipex);
		pipex->cmd_args = ft_split(argv[2 + pipex->index], ' ');
		if (!pipex->cmd_args)
			exit(1);
		if (ft_strrchr(pipex->cmd_args[0], '/') == 0)
		{
			if (!pipex->env_path)
				ft_exit(pipex, NULL, FORK, NO);
			pipex->cmd = get_cmd(pipex->cmd_paths, pipex->cmd_args[0]);
		}
		else
			pipex->cmd = pipex->cmd_args[0];
		if (!pipex->cmd || access(pipex->cmd, F_OK | X_OK) != 0)
			exit(1);
		if (execve(pipex->cmd, pipex->cmd_args, env) == -1)
			ft_exit(pipex, EXEC_ERROR, FORK, YES);
	}
}

// Manage the dup2 based on the position of the command
static void	manage_dup(t_pipe *pipex)
{
	if (pipex->index == 0)
	{
		if (pipex->err_infile == -1)
			ft_exit(pipex, NULL, PARSING, NO);
		if (dup2_double(pipex->infile, pipex->pipe[0][1]) == -1)
			ft_exit(pipex, NULL, PARSING, NO);
	}
	else if (pipex->index == pipex->nb_cmd - 1)
	{
		if (pipex->err_outfile == -1)
			ft_exit(pipex, NULL, PARSING, NO);
		if (dup2_double(pipex->pipe[pipex->index - 1][0], pipex->outfile) == -1)
			ft_exit(pipex, NULL, PARSING, NO);
	}
	else
		if (dup2_double(pipex->pipe[pipex->index - 1][0],
			pipex->pipe[pipex->index][1]) == -1)
			ft_exit(pipex, NULL, PARSING, NO);
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

// Parse input parameters to find the command to execute
static char	*get_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK | X_OK) == 0)
			return (command);
		free(command);
		path++;
	}
	return (NULL);
}
