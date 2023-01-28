/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:38:25 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/25 16:38:12 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_free_all(t_stack *stack, t_find f)
{
	if (stack)
	{
		if (stack->a)
			free(stack->a);
		if (stack->b)
			free(stack->b);
		free(stack);
	}
	if (f == BIGGER)
		exit (1);
	else
		exit (0);
}

void	ft_error(t_stack *stack)
{
	write(2, "Error\n", 6);
	ft_free_all(stack, BIGGER);
}
