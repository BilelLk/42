/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:10:00 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/20 16:10:00 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(fdf *data, int x, int y, int color)
{
	int	*dst;

	if (x > 1000 - 10 || y > 1000 - 10 || x < 10 || y < 10)
		return ;
	dst = (int *)data->addr;
	dst[y * 1000 + x] = color;
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
	points.x *= data->zoom;
	points.y *= data->zoom;
	points.x1 *= data->zoom;
	points.y1 *= data->zoom;
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	isometric(&points.x, &points.y, z);
	isometric(&points.x1, &points.y1, z1);
	points.x += data->shift_x;
	points.y += data->shift_y;
	points.x1 += data->shift_x;
	points.y1 += data->shift_y;
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