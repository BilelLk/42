/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:17:00 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/23 14:17:00 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_points *points, fdf	*data, int z, int z1)
{
	points->x = (points->x - points->y) * cos(data->angle_x);
	points->y = (points->x + points->y) * sin(data->angle_y) - z;
	points->x1 = (points->x1 - points->y1) * cos(data->angle_x);
	points->y1 = (points->x1 + points->y1) * sin(data->angle_y) - z1;
}

void	zoom(t_points *points, fdf *data)
{
	points->x *= data->zoom;
	points->y *= data->zoom;
	points->x1 *= data->zoom;
	points->y1 *= data->zoom;
}

void	shift(t_points *points, fdf *data)
{
	points->x += data->shift_x;
	points->y += data->shift_y;
	points->x1 += data->shift_x;
	points->y1 += data->shift_y;
}

void	color(fdf *data, int z, int z1)
{
	if (z || z1)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
}

void	init_data(fdf *data)
{
	data->angle_x = 0.8;
	data->angle_y = 0.8;
	data->shift_x = 800;
	data->shift_x = 800;
	data->zoom = 1;
	data->iso = 1;
	data->z_coef = 1;
}