/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_solve2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:39:06 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/09 14:21:17 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_mid_index(t_stack *stack, int value)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < stack->len_a)
	{
		if (value > stack->a[i] && value < stack->a[j])
			break ;
		i++;
		j++;
	}
	return (ft_side(j, stack->len_a));
}

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_move(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return (max(ft_abs(a), ft_abs(b)));
	return (ft_abs(a) + ft_abs(b));
}

void	ft_best_rr(t_stack *stack, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(stack);
		*a -= 1;
		*b -= 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(stack);
		*a += 1;
		*b += 1;
	}
}

void	ft_min_rotate(t_stack *stack, int *a, int *b)
{
	int	index_a;
	int	index_b;
	int	i;

	i = 0;
	while (i < stack->len_b)
	{
		if (stack->b[i] < ft_min(stack))
			index_a = ft_min_index(stack);
		else if (stack->b[i] > ft_max(stack))
			index_a = ft_max_index(stack);
		else
			index_a = ft_mid_index(stack, stack->b[i]);
		index_b = ft_side(i, stack->len_b);
		if (!i || get_move(index_a, index_b) < get_move(*a, *b))
		{
			*a = index_a;
			*b = index_b;
		}
		i++;
	}
}
