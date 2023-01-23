/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:23:00 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/23 09:23:00 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	maximum(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	modulo(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}
