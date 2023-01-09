/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:39:14 by blakehal          #+#    #+#             */
/*   Updated: 2022/12/31 19:39:14 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_rotate_up(int *stack, int *len)
{
	int	i;

	i = 0;
	*len -= 1;
	while (i < *len)
	{
		stack[i] = stack[i + 1];
		i++;
	}
}

void	ft_rotate_down(int *stack, int *len)
{
	int	i;

	i = 1;
	while (i <= *len)
	{
		stack[*len - i + 1] = stack[*len - i];
		i++;
	}
	*len += 1;
}
