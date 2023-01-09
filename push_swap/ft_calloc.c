/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:19:42 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/04 14:46:20 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			i;

	i = -1;
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (NULL);
	while (++i < (count * size))
		str[i] = 0;
	return (str);
}
