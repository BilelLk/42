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

void	ft_free_tab(fdf *data, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(data->z_matrix[j++]);
	free(data->z_matrix);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data);
	exit(0);
}

void	free_all(fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->z_matrix[i++]);
	free(data->z_matrix);
	free(data);
	exit(0);
}
