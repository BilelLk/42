/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:38:21 by blakehal          #+#    #+#             */
/*   Updated: 2022/12/31 19:38:21 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_rotate(int *stack, int *len)
{
	int	tmp;

	if (*len <= 1)
		return ;
	tmp = stack[0];
	ft_rotate_up(stack, len);
	stack[*len] = tmp;
	*len += 1;
}

void	ra(t_stack *stack)
{
	ft_rotate(stack->a, &stack->len_a);
	if (stack->print == 1)
		ft_putstr("ra");
}

void	rb(t_stack *stack)
{
	ft_rotate(stack->b, &stack->len_b);
	if (stack->print == 1)
		ft_putstr("rb");
}

void	rr(t_stack *stack)
{
	ft_rotate(stack->a, &stack->len_a);
	ft_rotate(stack->b, &stack->len_b);
	if (stack->print == 1)
		ft_putstr("rr");
}
