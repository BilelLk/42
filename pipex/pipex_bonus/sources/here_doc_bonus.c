/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:40:29 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/11 17:52:05 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipex_here_doc(t_pipe *pipex, char *limiter)
{
	char	*line;
	int		fd[2];

	limiter = ft_strjoin(limiter, "\n");
	if (!limiter || pipe(fd) == -1)
		ft_exit(pipex, NULL);
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!line || !ft_strncmp(line, limiter, ft_strlen(line)))
			break ;
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	if (line)
		free(line);
	free(limiter);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_exit(pipex, NULL);
	close(fd[0]);
	close(fd[1]);
}
