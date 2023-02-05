/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:28:31 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/12 14:35:24 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*destination;
	char	*source;
	int		taille;
	int		len_dest;

	destination = dest;
	source = (char *)src;
	taille = size;
	while (taille-- != 0 && *destination != '\0')
			destination++;
	len_dest = destination - dest;
	taille = size - len_dest;
	if (taille == 0)
		return (len_dest + ft_strlen(source));
	while (*source != '\0')
	{
		if (taille != 1)
		{
				*destination++ = *source;
				taille--;
		}
		source++;
	}
	*destination = '\0';
	return (len_dest + (source - src));
}
