/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:05:33 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/17 18:05:43 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_fdf *data, int three_d)
{
	data->posy = 0;
	while (data->posy < data->height)
	{
		data->posx = 0;
		while (data->posx < data->width)
		{
			if (data->posx < data->width - 1)
			{
				if (three_d == 1)
					draw_line(*data, data->posx + 1, data->posy);
				else
					draw_line_two_d(*data, data->posx + 1, data->posy);
			}
			if (data->posy < data->height - 1)
			{
				if (three_d == 1)
					draw_line(*data, data->posx, data->posy + 1);
				else
					draw_line_two_d(*data, data->posx, data->posy + 1);
			}
			data->posx++;
		}
		data->posy++;
	}
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIN_V - 10 || y > WIN_H - 10 || x < 10 || y < 10)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line_two_d(t_fdf data, float x1, float y1)
{
	double	delta_x;
	double	delta_y;
	int		nb_pixels;

	ft_z(&data, x1, y1);
	param_end_pos(&data);
	x1 *= data.coef;
	y1 *= data.coef;
	ft_pos(&data);
	x1 += data.shift_x;
	y1 += data.shift_y;
	param_color(&data);
	delta_x = x1 - data.posx;
	delta_y = y1 - data.posy;
	nb_pixels = max1(mod(delta_x), mod(delta_y)) + 1;
	delta_x /= nb_pixels;
	delta_y /= nb_pixels;
	while (nb_pixels--)
	{
		my_mlx_pixel_put(&data, data.posx, data.posy, data.color);
		data.posx += delta_x;
		data.posy += delta_y;
	}
}

void	draw_line(t_fdf data, float x1, float y1)
{
	double	delta_x;
	double	delta_y;
	int		nb_pixels;

	ft_z(&data, x1, y1);
	param_end_pos(&data);
	x1 *= data.coef;
	y1 *= data.coef;
	iso(&data.posx, &data.posy, data.z, &data);
	iso(&x1, &y1, data.z1, &data);
	ft_pos(&data);
	x1 += data.shift_x;
	y1 += data.shift_y;
	param_color(&data);
	delta_x = x1 - data.posx;
	delta_y = y1 - data.posy;
	nb_pixels = max1(mod(delta_x), mod(delta_y)) + 1;
	delta_x /= nb_pixels;
	delta_y /= nb_pixels;
	while (nb_pixels--)
	{
		my_mlx_pixel_put(&data, data.posx, data.posy, data.color);
		data.posx += delta_x;
		data.posy += delta_y;
	}
}
