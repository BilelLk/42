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

void	isometric(float  *x, float  *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
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