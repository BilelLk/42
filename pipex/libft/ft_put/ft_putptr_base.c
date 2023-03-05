/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:14:44 by blakehal          #+#    #+#             */
/*   Updated: 2023/02/27 20:14:38 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
