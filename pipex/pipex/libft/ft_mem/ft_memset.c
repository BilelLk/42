/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:12:55 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/12 14:28:26 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*k;

	k = b;
	while (len != 0)
	{
		*k = (unsigned char)c;
		k++;
		len--;
	}
	return (b);
}
