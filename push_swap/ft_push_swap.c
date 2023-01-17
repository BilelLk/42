/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:39:34 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/17 10:15:18 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_find_15_percent_smaller_bigger(int *array, int array_size, \
t_find f)
{
	float	ratio;
	int		i;
	int		nb_of_elements;

	i = 0;
	nb_of_elements = 0;
	ratio = 17;
	if (f == SMALLER)
	{
		while (i < array_size)
			if (array[i++] < array[0])
				nb_of_elements++;
	}
	else
	{
		while (i < array_size)
			if (array[i++] > array[0])
				nb_of_elements++;
	}
	if ((float)nb_of_elements >= \
	((float)array_size * (ratio / 100)))
		return (false);
	else
		return (true);
}

static void	ft_a_to_b(t_stack *stack)
{
	while (stack->len_a > 17)
	{
		if (!ft_find_15_percent_smaller_bigger(stack->a, stack->len_a, SMALLER))
		{
			if (!ft_find_15_percent_smaller_bigger(stack->a, stack->len_a, \
			BIGGER))
				ra(stack);
			else
				pb(stack);
		}
		else
		{
			pb(stack);
			if (!ft_find_15_percent_smaller_bigger(stack->a, stack->len_a, \
			BIGGER))
				rr(stack);
			else
				rb(stack);
		}
	}
	while (stack->len_a > 3)
	{
		pb(stack);
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
