/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:55:56 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/06 20:39:06 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	child(t_pipe *pipex, char **env);
static int	manage_dup(t_pipe *pipex);
static int	dup2_double(int in, int out);
static char	*get_cmd(char **path, char *cmd, t_pipe *pipex);
static void	print_err_cmd(char *cmd, t_pipe *pipex);

void	process(t_pipe *pipex, char **env)
{
	pipex->index = 0;
	while (pipex->index < pipex->nb_cmd)
	{
		child(pipex, env);
		pipex->index++;
	}
	// ft_close_everything(pipex);
}

// Create a child process using fork to execute command
static void	child(t_pipe *pipex, char **env)
{
	if (!pipex->index || (pipex->index > 0 && pipex->pid[pipex->index - 1]))
	{
		pipex->pid[pipex->index] = fork();
		if (pipex->pid[pipex->index] == -1)
			ft_exit(pipex, FORK_ERROR);
		// if (pipex->pid[pipex->index] != 0)
		// 	waitpid(-1, NULL, 0);
		if (pipex->pid[pipex->index] == 0)
		{
			if (parsing_error_cmd(pipex) == -1)
				return (ft_close_everything(pipex));
			pipex->cmd_args = ft_split(pipex->argv[2 + pipex->index], ' ');
			if (!pipex->cmd_args)
				return ;
			if (ft_strrchr(pipex->cmd_args[0], '/') == 0)
			{
				if (!pipex->env_path)
					ft_exit(pipex, NULL);
				pipex->cmd = get_cmd(pipex->cmd_paths, pipex->cmd_args[0], pipex);
			}
			else
				pipex->cmd = pipex->cmd_args[0];
			if (!pipex->cmd)
				return (ft_close_everything(pipex));
			if (manage_dup(pipex) == -1)
				return (ft_close_everything(pipex), parent_free(pipex), exit(1));
			ft_close_everything(pipex);
			execve(pipex->cmd, pipex->cmd_args, env);
			perror(pipex->cmd);
		}
	}
}

// Manage the dup2 based on the position of the command
static int	manage_dup(t_pipe *pipex)
{
	if (pipex->index == 0)
	{
		if (pipex->err_infile == -1)
			return (-1);
		if (dup2_double(pipex->infile, pipex->pipe[0][1]) == -1)
			return (-1);
	}
	else if (pipex->index == pipex->nb_cmd - 1)
	{
		if (pipex->err_outfile == -1)
			return (-1);
		if (dup2_double(pipex->pipe[pipex->index - 1][0], pipex->outfile) == -1)
			return (-1);
	}
	else
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

// static int	pipex_cmd(t_pipe *pipex)
// {
// 	if (ft_strrchr(pipex->cmd_args[0], '/') == 0)
// 	{
// 		if (!pipex->env_path)
// 			ft_exit(pipex, NULL);
// 		pipex->cmd = get_cmd(pipex->cmd_paths, pipex->cmd_args[0]);
// 	}
// 	else
// 		pipex->cmd = pipex->cmd_args[0];
// 	if (!pipex->cmd)
// 		return (-1);
// 	return (0);
// }

// Parse input parameters to find the command to execute
static char	*get_cmd(char **path, char *cmd, t_pipe *pipex)
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
	if (pipex->err_infile == -1 || pipex->err_outfile == -1)
	{
		if (pipex->index == 0 || pipex->index == pipex->nb_cmd - 1)
			return ;
		else
		{
			ft_putendl_fd(strerror(cmd),)
			perror(cmd);
			// write(2, cmd, ft_strlen(cmd));
			// ft_putendl_fd(": command not found", 2);
		}
	}
	else
	{
		execve(cmd, ft_split(cmd, ' '), NULL);
		perror(cmd);
		// write(2, cmd, ft_strlen(cmd));
		// ft_putendl_fd(": command not found", 2);
	}
}
