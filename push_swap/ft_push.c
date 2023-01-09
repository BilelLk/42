/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:38:12 by blakehal          #+#    #+#             */
/*   Updated: 2022/12/31 19:38:12 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_push(int *from, int *len_from, int *to, int *len_to)
{
	if (*len_from == 0)
		return ;
	ft_rotate_down(to, len_to);
	to[0] = from[0];
	ft_rotate_up(from, len_from);
}

void	pa(t_stack *stack)
{
	ft_push(stack->b, &stack->len_b, stack->a, &stack->len_a);
	if (stack->print == 1)
		ft_putstr("pa");
}

void	pb(t_stack *stack)
{
	ft_push(stack->a, &stack->len_a, stack->b, &stack->len_b);
	if (stack->print == 1)
		ft_putstr("pb");
}
