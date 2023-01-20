/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:50:07 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/14 09:31:05 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_first(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_last(char c, char const *set)
{
	int	i;

	i = ft_strlen(set);
	while (i >= 0)
	{
		if (set[i] == c)
			return (1);
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	len_s1;
	int	i;
	int	begin;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	if (s1[0] == 0)
		return (ft_substr(s1, 0, 1));
	len_s1 = ft_strlen(s1);
	while (ft_check_first(s1[i], set) == 1)
		i++;
	if (s1[i] == '\0')
		return (ft_calloc(sizeof(char), 1));
	begin = i;
	while (ft_check_last(s1[len_s1], set) == 1)
		len_s1--;
	return (ft_substr(s1, begin, (len_s1 - begin + 1)));
}
