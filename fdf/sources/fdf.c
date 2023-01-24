/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fdf.c                                              :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:05:00 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/20 14:05:00 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "define.h"

void	init_mlx(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (ft_free_tab(data, data->height - 1));
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_V, WIN_H, "FDF");
	if (!data->win_ptr)
		return (ft_free_tab(data, data->height - 1));
	data->img = mlx_new_image(data->mlx_ptr, WIN_V, WIN_H);
	if (!data->img)
		return (mlx_destroy_window(data->mlx_ptr, data->win_ptr), \
		ft_free_tab(data, data->height - 1));
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
		&data->line_length, &data->endian);
}

int	main(int argc, char **argv)
{
	t_fdf	data;

	if (argc != 2)
		return (0);
	ft_bzero(&data, sizeof (t_fdf));
	data.img = NULL;
	read_file(argv[1], &data);
	init_data(&data);
	init_mlx(&data);
	data.bits_per_pixel /= 8;
	data.zoom = 20;
	draw(&data);
	mlx_hook(data.win_ptr, DESTROYNOTIFY, (1l << 0), close_window, &data);
	mlx_hook(data.win_ptr, 02, (1l << 0), deal_key, &data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
	mlx_loop(data.mlx_ptr);
	free_all(&data);
}
