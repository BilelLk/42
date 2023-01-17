/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:07:20 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/17 18:11:26 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_nb_str(char *s, char c)
{
	int	wordcount;
	int	i;

	wordcount = 0;
	i = 0;
	while (s[i])
	{
		if (s[i + 1] == 0)
			break ;
		if (s[i] == c)
			while (s[i] == c)
				i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			wordcount++;
		}
	}
	return (wordcount);
}

void	get_data(char *file_name, t_fdf *data)
{
	int		i;
	int		fd;
	int		height;
	int		width;
	char	*line;

	width = 0;
	height = 0;
	i = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	width = ft_nb_str(line, ' ');
	free(line);
	data->width = width;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		height++;
	}
	data->height = height + 1;
	close(fd);
}

long	ft_atol(char *s)
{
	size_t	i;
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ')
		i++;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - 48);
	return (res * sign);
}

void	fill_matrix(t_fdf *data, int *matrix_line, char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	while (i < data->width)
	{
		matrix_line[i] = ft_atol(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums[i]);
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	get_data(file_name, data);
	data->matrix = malloc(sizeof(int *) * (data->height));
	if (!data->matrix)
		return ;
	while (i < data->height)
	{
		data->matrix[i] = malloc(sizeof(int) * (data->width));
		if (!data->matrix[i])
			ft_free_tab(data, i);
		i++;
	}
	i = 0;
	fd = open(file_name, O_RDONLY);
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data, data->matrix[i++], line);
		free(line);
	}
	close(fd);
}
