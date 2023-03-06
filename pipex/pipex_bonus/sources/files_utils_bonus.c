/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:55:12 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/06 13:25:47 by blakehal         ###   ########.fr       */
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
	while (i < pipex->nb_cmd -1)
	{
		pipex->pipe[i] = malloc(sizeof(int) * 2);
		if (!pipex->pipe[i])
			perror("pipex_pipe");
		else if (pipe(pipex->pipe[i]) == -1)
			perror("pipex_pipe");
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
