/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:30:21 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/12 16:56:02 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_init_struct(t_fdf *data)
{
	data->height = 0;
	data->width = 0;
	data->zoom = 4;
	data->x = 0;
	data->y = 0;
	data->color = 0;
	data->travel_l = 400;
	data->travel_r = 100;
	data->rotation_l = 0.8;
	data->rotation_r = 0.8;
	data->two_dimension = 1;
	data->side_dimension = 0;
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2 || open(argv[1], O_RDONLY) < 0)
		return (0);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		return (0);
	ft_init_struct(data);
}
