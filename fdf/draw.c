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

void	bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int 	max;
	int 	z;
	int 	z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	//----------------------------zoom-------------------------------------------
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	//----------------------------color-------------------------------------------
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	//-----------------------------3D--------------------------------------------
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	//-----------------------------Shift------------------------------------------
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	x_step = x1 - x;
	y_step = y1 - y;
	max = maximum(modulo(x_step), modulo(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(data, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}