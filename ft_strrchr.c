/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:15:25 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/12 19:12:41 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*b;
	int		j;

	b = (char *)s;
	j = ft_strlen(s);
	while (j >= 0)
	{
		if (b[j] == (char)c)
			return (&b[j]);
		j--;
	}
	return (NULL);
}
