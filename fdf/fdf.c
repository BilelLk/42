/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:05:00 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/20 14:05:00 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, fdf *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 53)
		free_all(data);
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->addr = mlx_get_data_addr(data->img, \
	&data->bits_per_pixel,&data->line_length, \
	&data->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->img, 0, 0);
	return (0);
}

int main(int argc, char **argv)
{
	fdf *data;

	if (argc != 2)
		return (0);
	data = (fdf *)malloc(sizeof(fdf));
	if (!data)
		exit (0);
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
		&data->line_length, &data->endian);
	data->bits_per_pixel /= 8;
	data->zoom = 20;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	mlx_loop(data->mlx_ptr);
	free_all(data);
}
