/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:12:34 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/19 10:29:51 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static int	u_conv(unsigned long nbr, unsigned int len_base, char *base)
{
	unsigned long	a;
	static int		i;

	i = 0;
	a = nbr;
	if (a >= len_base)
		u_conv((a / len_base), len_base, base);
	i += ft_putchar(base[nbr % 10]);
	return (i);
}

int	ft_putunbr_base(unsigned int nbr, char *base)
{
	unsigned int	len_base;

	len_base = ft_strlen(base);
	return (u_conv(nbr, len_base, base));
}
