/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:40:02 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/12 19:08:48 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*source;
	size_t	i;

	i = 0;
	source = (char *)s;
	while (i < n)
	{
		if (source[i] == (char)c)
		{
			return (&source[i]);
		}
		i++;
	}
	return (0);
}
