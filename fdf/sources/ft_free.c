/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:05:00 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/23 09:05:00 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_fdf *data)
{
	free_all(data);
	return (0);
}

void	ft_free_tab(t_fdf *data, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(data->z_matrix[j++]);
	free(data->z_matrix);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(EXIT_FAILURE);
}

void	free_all(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->z_matrix[i++]);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr && data->img)
		mlx_destroy_image(data->mlx_ptr, data->img);
	free(data->z_matrix);
	exit(0);
}
