/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:07:03 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/18 11:29:23 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_shift_param(t_fdf *data, int keycode, int cmd, int add)
{
	if (cmd == 0)
	{
		if (keycode == DOWN_ARROW)
			data->shift_y += add;
		if (keycode == UP_ARROW)
			data->shift_y -= add;
		if (keycode == RIGHT_ARROW)
			data->shift_x += add;
		if (keycode == LEFT_ARROW)
			data->shift_x -= add;
	}
	if (cmd == 1)
	{
		if (keycode == DOWN_ARROW)
			data->rotate_h += 0.1;
		if (keycode == UP_ARROW)
			data->rotate_h -= 0.1;
		if (keycode == RIGHT_ARROW)
			data->rotate_v += 0.1;
		if (keycode == LEFT_ARROW)
			data->rotate_v -= 0.1;
	}
}

void	ft_color(t_fdf *data)
{
	if (data->z <= 0 || data->z1 <= 5)
		data->color = BLUE;
	if ((data->z > 5 && data->z <= 50) || (data->z1 > 5 && data->z1 <= 50))
		data->color = GREEN;
	if ((data->z > 50 && data->z <= 200) || (data->z1 > 50 && data->z1 <= 200))
		data->color = BROWN;
	if ((data->z > 200) && (data->z1 > 200))
		data->color = WHITE;
}

void	ft_pos_end(t_fdf *data)
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
