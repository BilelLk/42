/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:43:00 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/23 16:43:00 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "define.h"

int	shift_key(int key, t_fdf *data)
{
	if (key == UP_SHIFT)
		data->shift_y -= 50;
	if (key == DOWN_SHIFT)
		data->shift_y += 50;
	if (key == LEFT)
		data->shift_x -= 50;
	if (key == RIGHT)
		data->shift_x += 50;
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, WIN_V, WIN_H);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

int	rotate_key(int key, t_fdf *data)
{
	if (key == W)
		data->angle_y -= 0.2;
	if (key == S)
		data->angle_y += 0.2;
	if (key == A)
		data->angle_x -= 0.2;
	if (key == D)
		data->angle_x += 0.2;
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, WIN_V, WIN_H);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

int	zoom_key(int key, t_fdf *data)
{
	if (key == MINUS)
		data->zoom -= 2;
	if (key == PLUS)
		data->zoom += 2;
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, WIN_V, WIN_H);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

int	iso_key(int key, t_fdf *data)
{
	if (key == SPACE)
	{
		if (data->iso == ISO)
			data->iso = 0;
		else
			data->iso = 1;
	}
	if (key == UP_ISO)
		data->z_coef += 1;
	if (key == DOWN_ISO)
		data->z_coef -= 1;
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, WIN_V, WIN_H);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

int	deal_key(int key, t_fdf *data)
{
	if (key == W || key == A || key == S || key == D)
		rotate_key(key, data);
	else if (key == UP_SHIFT || key == DOWN_SHIFT || key == RIGHT \
	|| key == LEFT)
		shift_key(key, data);
	else if (key == PLUS || key == MINUS)
		zoom_key(key, data);
	else if (key == SPACE || key == UP_ISO || key == DOWN_ISO)
		iso_key(key, data);
	else if (key == ESC)
		free_all(data);
	return (0);
}
