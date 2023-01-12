/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:39:34 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/12 13:11:43 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	is_top_30_percent(int *array, t_stacks s, int array_size, \
int total_len)
{
	float	ratio;
	int		i;
	int		nb_of_smaller_elements;

	i = 0;
	nb_of_smaller_elements = 0;
	ratio = (25 + (1 - array_size / (float)total_len) * 20);
	while (i < array_size)
		if (array[i++] < array[0])
			nb_of_smaller_elements++;
	if (s == A)
	{
		if ((float)nb_of_smaller_elements >= \
		((float)array_size * (ratio / 100)))
			return (true);
		else
			return (false);
	}
	else
	{
		if (nb_of_smaller_elements >= array_size / 3)
			return (true);
		else
			return (false);
	}
}

static void	ft_b_to_a(t_stack *stack)
{
	int			cost_a;
	int			cost_b;

	while (stack->len_b)
	{
		cost_a = 0;
		cost_b = 0;
		ft_min_rotate(stack, &cost_a, &cost_b);
		ft_best_rr(stack, &cost_a, &cost_b);
		ft_best_move(stack, A, cost_a);
		ft_best_move(stack, B, cost_b);
		pa(stack);
	}
	ft_best_move(stack, A, ft_side(ft_min_index(stack), stack->len_a));
}

static void	ft_a_to_b(t_stack *stack)
{
	int	movement_id;

	movement_id = 0;
	while (stack->len_a > 3)
	{
		movement_id = is_top_30_percent(stack->a, A, stack->len_a, stack->len);
		if (movement_id == 1)
		{
			if (stack->len_b > 0)
			{
				movement_id = is_top_30_percent(stack->b, B, \
				stack->len_b, stack->len);
				if (movement_id == 1)
					ra(stack);
				else
					rr(stack);
			}
			else
				ra(stack);
		}
		else
			pb(stack);
	}
}

static void	solve(t_stack *stack)
{
	ft_a_to_b(stack);
	ft_sort_three(stack);
	if (stack->len_a == 2 && stack->a[0] > stack->a[1])
		sa(stack);
	ft_b_to_a(stack);
}

int	main(int argc, char **argv)
{
	t_stack		*stack;

	if (argc == 1)
		return (0);
	stack = ft_parsing_stack(--argc, ++argv);
	if (!stack)
		return (1);
	if (ft_duplicates_stack(stack))
		ft_error(stack);
	stack->print = 1;
	stack->len = stack->len_a;
	if (ft_is_not_sorted(stack))
	{
		if (stack->len_a == 2)
			sa(stack);
		else if (stack->len_a == 3)
			ft_sort_three(stack);
		else if (stack->len_a == 4 || stack->len_a == 5)
			ft_sort_little(stack);
		else
			solve(stack);
	}
	ft_free_stack(stack, ALL);
	return (0);
}
