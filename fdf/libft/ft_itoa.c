/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:31:14 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/15 18:39:55 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*final;
	long	n_bis;
	int		len_final;

	len_final = ft_count(n);
	final = malloc(sizeof(char) * (len_final + 1));
	if (!final)
		return (NULL);
	final[len_final--] = '\0';
	n_bis = n;
	if (n_bis == 0)
	{
		final[0] = '0';
	}
	else if (n_bis < 0)
	{
		n_bis *= -1;
		final[0] = '-';
	}
	while (n_bis)
	{
		final[len_final--] = n_bis % 10 + '0';
		n_bis /= 10;
	}
	return (final);
}
