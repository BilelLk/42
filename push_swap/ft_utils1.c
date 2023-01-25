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

#include "ft_push_swap.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\n');
}

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

// void	*ft_free_stack(t_stack *stack, t_stacks stacks, t_find f)
// {
// 	if (stacks == A)
// 		free(stack->a);
// 	if (stacks == B)
// 		free(stack->b);
// 	if (stacks == ALL)
// 	{
// 	//	free(stack->a);
// 		free(stack->b);
// 	}
// 	free(stack);
//
// }
