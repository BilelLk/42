/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:38:54 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/12 12:38:54 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_swap(int *stack, int len)
{
	int	tmp;

	if (len > 1)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
	}
}

void	sa(t_stack *stack)
{
	ft_swap(stack->a, stack->len_a);
	if (stack->print == 1)
		ft_putstr("sa");
}

void	sb(t_stack *stack)
{
	ft_swap(stack->b, stack->len_b);
	if (stack->print == 1)
		ft_putstr("sb");
}

void	ss(t_stack *stack)
{
	ft_swap(stack->a, stack->len_a);
	ft_swap(stack->b, stack->len_b);
	if (stack->print == 1)
		ft_putstr("ss");
}
