/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_get_next_line_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:07:38 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/05 12:28:16 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_strrchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
