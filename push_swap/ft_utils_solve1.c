/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_solve1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:39:02 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/09 14:21:30 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_max(t_stack *stack)
{
	int		max;
	int		i;

	i = 0;
	max = stack->a[0];
	while (i != stack->len_a)
	{
		if (max < stack->a[i])
			max = stack->a[i];
		i++;
	}
	return (max);
}

int	ft_max_index(t_stack *stack)
{
	int		max;
	int		i;

	i = 0;
	max = ft_max(stack);
	while (i != stack->len_a)
	{
		if (max == stack->a[i])
			break ;
		i++;
	}
	return (ft_side(++i, stack->len_a));
}
