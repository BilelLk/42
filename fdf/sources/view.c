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
#include "define.h"

void	isometric(t_points *points, t_fdf	*data, int z, int z1)
{
	points->x = (points->x - points->y) * cos(data->angle_x);
	points->y = (points->x + points->y) * sin(data->angle_y) - z;
	points->x1 = (points->x1 - points->y1) * cos(data->angle_x);
	points->y1 = (points->x1 + points->y1) * sin(data->angle_y) - z1;
}

void	zoom(t_points *points, t_fdf *data)
{
	points->x *= data->zoom;
	points->y *= data->zoom;
	points->x1 *= data->zoom;
	points->y1 *= data->zoom;
}

void	shift(t_points *points, t_fdf *data)
{
	points->x += data->shift_x;
	points->y += data->shift_y;
	points->x1 += data->shift_x;
	points->y1 += data->shift_y;
}

void	set_color(t_points *points, t_fdf *data)
{
	if (points->z <= 0 || points->z1 <= 5)
		data->color = BLUE;
	if ((points->z > 5 && points->z <= 50) || \
	(points->z1 > 5 && points->z1 <= 50))
		data->color = GREEN;
	if ((points->z > 50 && points->z <= 200) || \
	(points->z1 > 50 && points->z1 <= 200))
		data->color = BROWN;
	if ((points->z > 200) && (points->z1 > 200))
		data->color = YELLOW;
}

void	init_data(t_fdf *data)
{
	data->angle_x = ANGLE;
	data->angle_y = ANGLE;
	data->shift_x = SHIFT;
	data->shift_x = SHIFT;
	data->zoom = ZOOM;
	data->iso = ISO;
	data->z_coef = Z_COEF;
}
