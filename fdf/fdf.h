/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:06:21 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/18 11:33:47 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# ifndef WIN_H
#  define WIN_H			1080
# endif
# ifndef WIN_V
#  define WIN_V			1920
# endif
# define KEYRELEASE		1l << 0
# define BUTTONPRESS	1L << 2
# define LEFT_ARROW 	123
# define RIGHT_ARROW 	124
# define UP_ARROW 		126
# define DOWN_ARROW 	125
# define FLAT_VIEW		3
# define ESC			53
# define CMD			259
# define ALT			261
# define BLUE			0x0000FF
# define GREEN			0x008000
# define BROWN			0x724b15
# define WHITE			0xFFF8DC

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		**matrix;
	int		coef;
	int		shift_x;
	int		shift_y;
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	posx;
	float	posy;
	int		z;
	int		z1;
	int		color;
	float	rotate_h;
	float	rotate_v;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_fdf;

typedef struct s_points
{
	float	x;
	float	x1;
	float	y;
	float	y1;
}				t_points;

void	read_file(char *file_name, t_fdf *data);
int		ft_nb_str(char *s, char c);
void	draw_line(t_fdf data, float x1, float y1);
void	draw(t_fdf *data, int three_d);
void	ft_isometric_view(float *x, float *y, int z, t_fdf *data);
void	free_all(t_fdf *data);
int		close_window(t_fdf *data);
void	free_all(t_fdf *data);
void	ft_shift_param(t_fdf *data, int keycode, int cmd, int add);
void	ft_init(t_fdf *data);
void	ft_color(t_fdf *data);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
int		max1(int a, int b);
float	mod(float i);
int		deal_key(int keycode, t_fdf *data);
int		mouse_hook(int keycode, int x, int y, t_fdf *data);
void	ft_pos_end(t_fdf *data);
void	ft_z(t_fdf *data, float x1, float y1);
void	ft_pos(t_fdf *data);
void	ft_free_tab(t_fdf *data, int i);
void	free_all(t_fdf *data);
int		three_d(int keycode, t_fdf *data);
void	draw_line_two_d(t_fdf data, float x1, float y1);

#endif