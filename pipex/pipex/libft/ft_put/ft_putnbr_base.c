/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:25:25 by blakehal          #+#    #+#             */
/*   Updated: 2023/02/27 20:14:25 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	base_conv(unsigned int nbr, unsigned int len_base, char *base)
{
	unsigned long long int	a;
	static int				i;
	static int				sign;

	i = 0;
	sign = 1;
	a = nbr;
	if (a >= len_base)
		base_conv((a / len_base), len_base, base);
	i += ft_putchar(base[a % len_base]);
	return (i * sign);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	len_base;

	len_base = ft_strlen(base);
	return (base_conv(nbr, len_base, base));
}
