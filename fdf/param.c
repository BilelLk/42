/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:07:03 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/17 18:07:11 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	param_shift(t_fdf *data, int keycode, int cmd, int add)
{
	if (cmd == 0)
	{
		if (keycode == 126)
			data->shift_y += add;
		if (keycode == 125)
			data->shift_y -= add;
		if (keycode == 123)
			data->shift_x += add;
		if (keycode == 124)
			data->shift_x -= add;
	}
	if (cmd == 1)
	{
		if (keycode == 126)
			data->rotate_h += 0.05;
		if (keycode == 125)
			data->rotate_h -= 0.05;
		if (keycode == 123)
			data->rotate_v += 0.05;
		if (keycode == 124)
			data->rotate_v -= 0.05;
	}
}

void	param_color(t_fdf *data)
{
	if (data->z <= 0 || data->z1 <= 5)
		data->color = 0x0000FF;
	if ((data->z > 5 && data->z <= 50) || (data->z1 > 5 && data->z1 <= 50))
		data->color = 0x008000;
	if ((data->z > 50 && data->z <= 200) || (data->z1 > 50 && data->z1 <= 200))
		data->color = 0x724b15;
	if ((data->z > 200) && (data->z1 > 200))
		data->color = 0xFFF8DC;
}

void	param_end_pos(t_fdf *data)
{
	data->posx *= data->coef;
	data->posy *= data->coef;
}

void	ft_z(t_fdf *data, float x1, float y1)
{
	data->z = data->matrix[(int)data->posy][(int)data->posx];
	data->z1 = data->matrix[(int)y1][(int)x1];
}

void	ft_pos(t_fdf *data)
{
	data->posx += data->shift_x;
	data->posy += data->shift_y;
}
