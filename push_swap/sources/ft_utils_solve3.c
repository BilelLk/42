/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_solve3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:38:34 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/12 12:38:36 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_best_move(t_stack *stack, t_stacks s, int index)
{
	while (index)
	{
		if (index < 0)
		{
			if (s == A)
				rra(stack);
			else
				rrb(stack);
			index++;
		}
		else
		{
			if (s == A)
				ra(stack);
			else
				rb(stack);
			index--;
		}
	}
}

void	ft_sort_three(t_stack *stack)
{
	int	top;
	int	mid;
	int	bot;

	top = stack->a[0];
	mid = stack->a[1];
	bot = stack->a[2];
	if (stack->len_a == 2)
		sa(stack);
	if (top > mid && mid > bot && top > bot)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > mid && bot > mid && top > bot)
		ra(stack);
	else if (mid > top && mid > bot && bot > top)
	{
		sa(stack);
		ra(stack);
	}
	else if (top > mid && bot > mid && bot > top)
		sa(stack);
	else if (mid > top && mid > bot && top > bot)
		rra(stack);
}

int	ft_min_index(t_stack *stack)
{
	int		min;
	int		i;
	int		j;

	i = 0;
	j = 0;
	min = ft_min(stack);
	while (i != stack->len_a)
	{
		if (min == stack->a[i])
			break ;
		i++;
	}
	return (ft_side(i, stack->len_a));
}

int	ft_side(int i, int len)
{
	if (i >= (len + 1) / 2)
		return ((len - i) * -1);
	return (i);
}

int	ft_min(t_stack *stack)
{
	int		min;
	int		i;

	i = 0;
	min = stack->a[0];
	while (i != stack->len_a)
	{
		if (min > stack->a[i])
			min = stack->a[i];
		i++;
	}
	return (min);
}
