/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:40:00 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/20 11:40:00 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>

# ifndef WIN_H
#  define WIN_H 1080
# endif
# ifndef WIN_V
#  define WIN_V 1920
# endif

typedef struct  s_fdf
{
	int		**z_matrix;
	int		xmax;
	int		ymax;

    int		width;
    int		height;
	int		zoom;
	int		color;
	int		iso;
	int		z_coef;

	int		shift_x;
	int		shift_y;
	float	angle_x;
	float	angle_y;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void	*mlx_ptr;
	void	*win_ptr;
}   fdf;

typedef struct s_points
{
	float	x;
	float	x1;
	float	y;
	float	y1;
}			t_points;

void    read_file(char *file_name, fdf *data);
void	bresenham(t_points points, fdf *data);
void	draw(fdf *data);
void	free_all(fdf *data);
void	ft_free_tab(fdf *data, int i);
float	maximum(float a, float b);
float	modulo(float a);
float	mod(float i);
void	isometric(t_points *points, fdf	*data, int z, int z1);
void	zoom(t_points *points, fdf *data);
void	shift(t_points *points, fdf *data);
void	color(fdf *data, int z, int z1);
void	init_data(fdf *data);
int		deal_key(int key, fdf *data);

#endif