/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:02:49 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/14 10:58:26 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*final;
	int				len_final;

	i = 0;
	if (!s || !(*f))
		return (NULL);
	len_final = ft_strlen(s);
	final = malloc(sizeof(char) * len_final + 1);
	if (!final)
		return (NULL);
	while (s[i])
	{
		final[i] = (*f)(i, s[i]);
		i++;
	}
	final[i] = 0;
	return (final);
}
