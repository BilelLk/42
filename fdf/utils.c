/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:07:37 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/17 18:08:15 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->rotate_v);
	*y = (*x + *y) * sin(data->rotate_h) - z;
}

int	max1(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}
