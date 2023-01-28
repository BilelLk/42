/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_not_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:35:14 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/04 14:46:20 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	ft_is_not_sorted(t_stack *a)
{
	t_stack	*temp;
	int		value;
	int		i;

	i = 0;
	temp = a;
	value = temp->a[0];
	while (i != temp->len_a)
	{
		if (value > temp->a[i])
		{
			return (true);
		}
		value = temp->a[i];
		i++;
	}
	return (false);
}

int	ft_duplicates_stack(t_stack *a)
{
	t_stack	*temp;
	t_stack	*temp1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = a;
	while (j != temp->len_a)
	{
		temp1 = temp;
		while (i != temp1->len_a - 1)
		{
			i++;
			if (temp->a[j] == temp1->a[i])
			{
				return (true);
			}
		}
		j++;
		i = j;
	}
	return (false);
}
