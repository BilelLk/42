/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_little.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:13:56 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/04 14:46:20 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_little(t_stack *stack)
{
	while (stack->len_a > 3)
	{
		ft_best_move(stack, A, ft_min_index(stack));
		pb(stack);
	}
	ft_sort_three(stack);
	pa(stack);
	pa(stack);
}
