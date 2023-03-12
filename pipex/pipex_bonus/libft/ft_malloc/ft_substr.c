/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:08:35 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/16 09:54:47 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_test(char const *s, unsigned int start, size_t len, char *final)
{
	size_t	i;

	i = 0;
	while (s[start] && i < len)
	{
		final[i] = s[start];
		i++;
		start++;
	}
	final[i] = 0;
	return (final);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*final;

	if (!s)
		return (NULL);
	else if (start >= ft_strlen(s))
	{
		final = malloc(sizeof(char));
		if (!final)
			return (NULL);
		final[0] = 0;
		return (final);
	}
	else if (len > ft_strlen(s + start))
	{
		final = malloc(sizeof(char) * ft_strlen(s + start) + 1);
		if (!final)
			return (NULL);
		return (ft_test(s, start, len, final));
	}
	final = malloc(sizeof(char) * len + 1);
	if (!final)
		return (NULL);
	return (ft_test(s, start, len, final));
}
