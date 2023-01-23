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



int main(int argc, char **argv)
{
	fdf *data;

	if (argc != 2)
		return (0);
	data = (fdf *)malloc(sizeof(fdf));
	if (!data)
		exit (0);
	read_file(argv[1], data);
	init_data(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_V, WIN_H, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, WIN_V, WIN_H);
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
