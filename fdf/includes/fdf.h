/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:00:56 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/12 16:52:14 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>

# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define UP_ARROW 126
# define DOWN_ARROW 125
# define ZOOM_IN_KEY 34
# define ZOOM_OUT_KEY 31
# define A_KEY 1
# define W_KEY 2
# define S_KEY 0
# define D_KEY 13
# define B_KEY 11
# define ESC_KEY 53
# define ON_DESTROY 17
# define H_KEY 4
# define WIN_W 2000
# define WIN_H 2000
# define CLR_DISCO			10100586
# define CLR_BRICK_RED		12724558
# define CLR_FLAMINGO		15485735
# define CLR_JAFFA			15697459
# define CLR_SAFFRON		15970109
# define CLR_BLUE			2003199


typedef struct s_fdf
{
	float	x;
	float	y;
	int		z;
	int		z1;

	int		width;
	int		height;
	int		**z_matrix;

	int		zoom;
	int		color;
	int		travel_l;
	int		travel_r;
	float	rotation_r;
	float	rotation_l;
	int		two_dimension;
	int		side_dimension;

	void	*mlx_ptr;
	void	*win_ptr;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_fdf;



#endif