/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:38:25 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/12 12:38:25 by blakehal         ###   ########lyon.fr   */
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

void	ft_error(t_stack *stack)
{
	if (stack)
		ft_free_stack(stack, ALL);
	write(2, "Error\n", 6);
	exit(-1);
}

void	*ft_free_stack(t_stack *stack, t_stacks stacks)
{
	if (stacks)
		free(stack->a);
	if (stacks == ALL)
		free(stack->b);
	free(stack);
	return (NULL);
}
