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

int	shift_key(int key, fdf *data)
{
	if (key == 126)
		data->shift_y -= 50;
	if (key == 125)
		data->shift_y += 50;
	if (key == 123)
		data->shift_x -= 50;
	if (key == 124)
		data->shift_x += 50;
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, WIN_V, WIN_H);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
								  &data->line_length, &data->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

int	rotate_key(int key, fdf *data)
{
	if (key == 13)
		data->angle_y -= 0.2;
	if (key == 1)
		data->angle_y += 0.2;
	if (key == 0)
		data->angle_x -= 0.2;
	if (key == 2)
		data->angle_x += 0.2;
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, WIN_V, WIN_H);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
								   &data->line_length, &data->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

int	zoom_key(int key, fdf *data)
{
	if (key == 78)
		data->zoom -= 2;
	if (key == 69)
		data->zoom += 2;
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, WIN_V, WIN_H);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
								   &data->line_length, &data->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

int	iso_key(int key, fdf *data)
{
	if (key == 49)
	{
		if (data->iso == 1)
			data->iso = 0;
		else
			data->iso = 1;
	}
	if (key == 116)
		data->z_coef += 1;
	if (key == 121)
		data->z_coef -= 1;
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, WIN_V, WIN_H);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
								   &data->line_length, &data->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

int	deal_key(int key, fdf *data)
{
	if (key == 13 || key == 0 || key == 1 || key == 2)
		rotate_key(key, data);
	else if (key == 126 || key == 125 || key == 124 || key == 123)
		shift_key(key, data);
	else if (key == 69 || key == 78)
		zoom_key(key, data);
	else if (key == 49 || key == 116 || key == 121)
		iso_key(key, data);
	else if (key == 53)
		free_all(data);
	return (0);
}


//int	deal_key(int key, fdf *data)
//{
//	if (key == 126)
//		data->shift_y -= 10;
//	if (key == 125)
//		data->shift_y += 10;
//	if (key == 123)
//		data->shift_x -= 10;
//	if (key == 124)
//		data->shift_x += 10;
//	if (key == 53)
//		free_all(data);
//	mlx_destroy_image(data->mlx_ptr, data->img);
//	data->img = mlx_new_image(data->mlx_ptr, WIN_V, WIN_H);
//	data->addr = mlx_get_data_addr(data->img, \
//	&data->bits_per_pixel,&data->line_length, \
//	&data->endian);
//	draw(data);
//	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
//	data->img, 0, 0);
//	return (0);
//}
