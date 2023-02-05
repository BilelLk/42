/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fdf.h                                              :+:      :+:    :+: */
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
# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct s_fdf
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
}	t_fdf;

typedef struct s_points
{
	float	x;
	float	x1;
	float	y;
	float	y1;
	int		z;
	int		z1;
}			t_points;

void	read_file(char *file_name, t_fdf *data);
void	bresenham(t_points points, t_fdf *data);
void	draw(t_fdf *data);
void	free_all(t_fdf *data);
void	ft_free_tab(t_fdf *data, int i);
float	maximum(float a, float b);
float	modulo(float a);
float	mod(float i);
void	isometric(t_points *points, t_fdf	*data, int z, int z1);
void	zoom(t_points *points, t_fdf *data);
void	shift(t_points *points, t_fdf *data);
void	color(t_fdf *data, int z, int z1);
void	init_data(t_fdf *data);
int		deal_key(int key, t_fdf *data);
void	set_color(t_points *points, t_fdf *data);
int		close_window(t_fdf *data);
int		ft_wordcounter(char const *s, char c);

#endif