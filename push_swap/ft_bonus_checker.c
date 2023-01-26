/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:37:39 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/25 16:37:10 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

static int	ft_str_cmp(char *s1, char *s2)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	j = s1[i] - s2[i];
	if (j == 10)
		return (true);
	return (false);
}

static void	ft_instructions(char *line, t_stack *stack)
{
	if (ft_str_cmp(line, "sa"))
		sa(stack);
	else if (ft_str_cmp(line, "sb"))
		sb(stack);
	else if (ft_str_cmp(line, "ss"))
		ss(stack);
	else if (ft_str_cmp(line, "pa"))
		pa(stack);
	else if (ft_str_cmp(line, "pb"))
		pb(stack);
	else if (ft_str_cmp(line, "ra"))
		ra(stack);
	else if (ft_str_cmp(line, "rb"))
		rb(stack);
	else if (ft_str_cmp(line, "rr"))
		rr(stack);
	else if (ft_str_cmp(line, "rra"))
		rra(stack);
	else if (ft_str_cmp(line, "rrb"))
		rrb(stack);
	else if (ft_str_cmp(line, "rrr"))
		rrr(stack);
	else
		ft_error(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	*line;

	if (argc == 1)
		return (0);
	stack = ft_parsing_stack(--argc, ++argv);
	if (!stack)
		return (1);
	if (ft_duplicates_stack(stack))
		return (ft_error(stack), 1);
	stack->print = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ft_instructions(line, stack);
		free(line);
	}
	printf("stack->b[0] = %d\n", stack->b[0]);
	if (ft_is_not_sorted(stack) || (!ft_is_not_sorted(stack) && stack->len_b))
		ft_putstr("\033[91mKO\033[0m");
	else
		ft_putstr("\033[92mOK\033[0m");
	return (ft_free_all(stack, SMALLER), 0);
}
