/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:27:24 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/04 14:46:20 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_malloc_clear(char **strs, int a)
{
	if (!strs[a])
	{
		while (a >= 0)
		{
			free(strs[a]);
			a--;
		}
		free(strs);
		return (1);
	}
	return (0);
}

static int	ft_wordcount(char const *s, char c)
{
	int	wordcount;
	int	i;

	wordcount = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
			i++;
		}
		if (s[i] == '\0')
			break ;
		while (s[i] && s[i] != c)
			i++;
		wordcount++;
	}
	return (wordcount);
}

static char	**ft_spliplit(char const *s, char **final, char c, int i)
{
	int	begin;
	int	j;

	begin = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			while (s[i] == c)
				i++;
		if (s[i] == '\0')
			break ;
		begin = i;
		while (s[begin] && s[begin] != c)
			begin ++;
		final[j] = ft_substr(s, i, begin - i);
		if (j <= ft_wordcount(s, c) && ft_malloc_clear(final, j))
			return (NULL);
		j++;
		i = begin;
	}
	return (final);
}

char	**ft_split(char const *s, char c)
{
	char	**final;

	if (!s)
		return (0);
	final = ft_calloc(sizeof(char *), ft_wordcount(s, c) + 1);
	if (!final)
		return (NULL);
	return (ft_spliplit(s, final, c, 0));
}
