/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:55:12 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/11 15:15:21 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// Close both ends of the generated pipe
void	close_pipes(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->nb_cmd && pipex->pipe[i])
	{
		close(pipex->pipe[i][0]);
		close(pipex->pipe[i][1]);
		i++;
	}
}

// Create pipes
void	create_pipes(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->nb_cmd - 1)
	{
		pipex->pipe[i] = ft_calloc(2, sizeof(int));
		if (!pipex->pipe[i])
			return (perror("pipex_pipe"), ft_exit(pipex, NULL));
		else if (pipe(pipex->pipe[i]) == -1)
			return (perror("pipex_pipe"), ft_exit(pipex, NULL));
		i++;
	}
}

char	*find_path(char **env)
{
	if (!env[0])
		return (NULL);
	while (ft_strncmp(PATH_PREFIX, *env, 5))
	{
		env++;
		if (!*env)
			return (NULL);
	}
	return (*env + 5);
}

int	check_right(t_pipe *pipex)
{
	if (!pipex->index && pipex->infile == -1)
		return (-1);
	if (pipex->index == (pipex->argc - (4 + pipex->here_doc)) && \
		pipex->outfile == -1)
		return (-1);
	return (0);
}

void	ft_error_argc(t_pipe *pipex)
{
	ft_putendl_fd(ARG_ERROR, 2);
	if (pipex->here_doc)
		ft_putendl_fd(HERE_DOC_MODEL, 2);
	else
		ft_putendl_fd(PIPE_MODEL, 2);
	exit(1);
}
