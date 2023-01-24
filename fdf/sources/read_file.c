/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:08:00 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/24 08:39:43 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_height(t_fdf *data, char *file_name)
{
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		exit (1);
	data->height = 0;
	line = get_next_line(fd);
	if (!line)
		return (close(fd), exit(1));
	data->xmax = ft_wordcounter(line, ' ');
	while (line != NULL)
	{
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
	data->ymax = data->height;
	data->width = data->xmax;
}

int	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	if (!nums)
		return (EXIT_FAILURE);
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
	return (EXIT_SUCCESS);
}

void	fill_height_width(t_fdf *data)
{
	int	i;

	i = -1;
	if (!data->z_matrix)
		exit (1);
	while (++i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof (int) * (data->width));
		if (!data->z_matrix[i])
			ft_free_tab(data, i);
	}
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	get_height(data, file_name);
	data->z_matrix = (int **)malloc(sizeof (int *) * (data->height + 1));
	fill_height_width(data);
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		return (ft_free_tab(data, data->height - 1));
	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (close(fd), ft_free_tab(data, data->height - 1));
	while (line != NULL)
	{
		if (fill_matrix(data->z_matrix[i], line) == EXIT_FAILURE)
			return (free(line), close(fd), ft_free_tab(data, data->height - 1));
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	data->z_matrix[i] = NULL;
}
