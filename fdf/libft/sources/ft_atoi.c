/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:55:01 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/16 10:10:41 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whitesapce(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		i++;
	else if (str[i] == '+')
		i++;
	return (i);
}

static int	ft_sign(const char *str)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		return (sign);
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	long long int	finale;
	int				i;
	int				sign;

	sign = ft_sign(str);
	finale = 0;
	i = ft_whitesapce(str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (finale != ((finale * 10 + (sign * (str[i] - '0'))) / 10))
			return ((int)((sign + 1) / 2 / -1));
		finale = finale * 10 + ((str[i] - '0') * sign);
		i++;
	}
	return ((int)finale);
}
