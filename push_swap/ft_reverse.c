/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:38:03 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/12 12:38:03 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_push_swap.h"

static void	ft_reverse(int *stack, int *len)
{
	int	tmp;

	if (*len <= 1)
		return ;
	*len -= 1;
	tmp = stack[*len];
	ft_rotate_down(stack, len);
	stack[0] = tmp;
}

void	rra(t_stack *stack)
{
	ft_reverse(stack->a, &stack->len_a);
	if (stack->print == 1)
		ft_putstr("rra");
}

void	rrb(t_stack *stack)
{
	ft_reverse(stack->b, &stack->len_b);
	if (stack->print == 1)
		ft_putstr("rrb");
}

void	rrr(t_stack *stack)
{
	ft_reverse(stack->a, &stack->len_a);
	ft_reverse(stack->b, &stack->len_b);
	if (stack->print == 1)
		ft_putstr("rrr");
}
