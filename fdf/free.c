/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:06:36 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/17 18:06:42 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_tab(t_fdf *data, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(data->matrix[j++]);
	free(data->matrix);
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
}

void	free_all(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->matrix[i++]);
	free(data->matrix);
	free(data);
	exit(0);
}
