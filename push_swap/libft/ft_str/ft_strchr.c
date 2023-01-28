/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:46:58 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/12 19:11:31 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*b;
	int		i;

	i = 0;
	b = (char *)s;
	while (b[i] && b[i] != (char)c)
		i++;
	if (b[i] == (char)c)
		return (&b[i]);
	return (NULL);
}
