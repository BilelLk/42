/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:14:44 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/19 10:56:45 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_conv(unsigned long long nbr, char *base)
{
	unsigned long	a;
	static int		i;

	i = 0;
	a = nbr;
	if (a > 15)
		ptr_conv((a / 16), base);
	i += ft_putchar(base[nbr % 16]);
	return (i);
}

int	ft_putptr_base(unsigned long long nbr, char *base)
{
	write(1, "0x", 2);
	return (ptr_conv(nbr, base) + 2);
}
