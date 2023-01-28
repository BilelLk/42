/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:55:29 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/19 10:27:28 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nbr)
{
	unsigned long	a;
	static int		i;
	int				sign;

	i = 0;
	sign = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		a = -nbr;
		write(1, "-", 1);
		sign++;
	}
	else
		a = nbr;
	if (a > 9)
		ft_putnbr(a / 10);
	i += ft_putchar((a % 10) + 48);
	return (i + sign);
}
