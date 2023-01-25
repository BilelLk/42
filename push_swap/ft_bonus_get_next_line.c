/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_get_next_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:02:41 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/25 15:47:07 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static char	*ft_clean(char *tmp)
{
	char		*swap;
	size_t		i;
	size_t		j;

	i = 0;
	if (!tmp)
		return (NULL);
	while (tmp[i] != '\n' && tmp[i])
		i++;
	if (tmp[i] == '\0')
		return (free(tmp), NULL);
	if (tmp[i] == '\n')
		i++;
	swap = malloc(sizeof(char) * ((ft_strlen(tmp) - i) + 1));
	if (!swap)
		return (NULL);
	j = 0;
	while (tmp[i])
		swap[j++] = tmp[i++];
	swap[j] = '\0';
	return (free(tmp), tmp = NULL, swap);
}

static char	*ft_implement(char *tmp)
{
	char		*final;
	size_t		i;

	i = 0;
	if (!tmp[i])
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	final = malloc(sizeof(char) * (i + 1));
	if (!final)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		final[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		return (final[i] = '\n', final[i + 1] = '\0', final);
	return (final[i] = '\0', final);
}

static char	*ft_strjoin(char *tmp, char *buffer)
{
	char		*final;
	size_t		i;
	size_t		j;

	if (!tmp)
	{
		tmp = malloc(sizeof(char) * 1);
		if (!tmp)
			return (NULL);
		tmp[0] = '\0';
	}
	final = malloc(sizeof(char) * (ft_strlen(tmp) + ft_strlen(buffer) + 1));
	if (!final)
		return (free(tmp), NULL);
	i = 0;
	j = 0;
	while (tmp[j])
		final[i++] = tmp[j++];
	j = 0;
	while (buffer[j])
		final[i++] = buffer[j++];
	final[i] = 0;
	return (free(tmp), tmp = NULL, final);
}

static char	*ft_read(int fd, char *tmp)
{
	char	buffer[BUFFER_SIZE + 1];
	int		nb_bytes;

	nb_bytes = 1;
	while (!ft_strrchr(tmp, '\n') && nb_bytes != 0)
	{
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nb_bytes == -1)
			return (NULL);
		buffer[nb_bytes] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (!tmp)
			return (NULL);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (free(tmp), tmp = NULL, NULL);
	tmp = ft_read(fd, tmp);
	if (!tmp)
		return (NULL);
	line = ft_implement(tmp);
	tmp = ft_clean(tmp);
	return (line);
}
