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

typedef struct  s_fdf
{
    int		width;
    int		height;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
    int		**z_matrix;
    void	*mlx_ptr;
    void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}   fdf;

void    read_file(char *file_name, fdf *data);
void	bresenham(float x, float y, float x1, float y1, fdf *data);
void	draw(fdf *data);
void	free_all(fdf *data);
void	ft_free_tab(fdf *data, int i);
float	maximum(float a, float b);
float	modulo(float a);
float	mod(float i);
void	isometric(float  *x, float  *y, int z);

#endif