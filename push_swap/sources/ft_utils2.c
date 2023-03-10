/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:38:12 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/12 12:38:12 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

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
