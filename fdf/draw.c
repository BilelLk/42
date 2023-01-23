/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:10:00 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/23 16:56:08 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(fdf *data, int x, int y, int color)
{
	int	*dst;

	if (x > WIN_V - 10 || y > WIN_H - 10 || x < 10 || y < 10)
		return ;
	dst = (int *)data->addr;
	dst[y * WIN_V + x] = color;
}

void	bresenham(t_points points, fdf *data)
{
	float	x_step;
	float	y_step;
	int 	max;
	int 	z;
	int 	z1;

	z = data->z_matrix[(int)points.y][(int)points.x];
	z1 = data->z_matrix[(int)points.y1][(int)points.x1];
	zoom(&points, data);
	color(data, z, z1);
	if (data->iso == 1)
		isometric(&points, data, z, z1);
	shift(&points, data);
	x_step = points.x1 - points.x;
	y_step = points.y1 - points.y;
	max = maximum(modulo(x_step), modulo(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(points.x - points.x1) || (int)(points.y - points.y1))
	{
		my_mlx_pixel_put(data, points.x, points.y, data->color);
		points.x += x_step;
		points.y += y_step;
	}
}

void	draw(fdf *data)
{
	t_points	points;

	points.y = 0;
	while (points.y < data->ymax)
	{
		points.x = 0;
		while (points.x < data->xmax)
		{
			if (points.x < data->xmax - 1)
			{
				points.x1 = (points.x) + 1;
				points.y1 = points.y;
				bresenham(points, data);
			}
			if (points.y < data->ymax - 1)
			{
				points.x1 = points.x;
				points.y1 = points.y + 1;
				bresenham(points, data);
			}
			points.x++;
		}
		points.y++;
	}
}