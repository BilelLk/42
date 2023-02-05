/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:51:46 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/19 11:09:06 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_conversion(const char *format, int i, va_list args, int len)
{
	char	*base;

	base = "0123456789abcdef";
	if (format[i] == 'c')
		len = ft_putchar((int) va_arg(args, int));
	else if (format[i] == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (format[i] == 'p')
		len = ft_putptr_base(va_arg(args, unsigned long long), base);
	else if (format[i] == 'u')
		len = ft_putunbr_base(va_arg(args, long), "0123456789");
	else if (format[i] == 'x')
		len = ft_putnbr_base(va_arg(args, unsigned int), base);
	else if (format[i] == 'X')
	{
		base = "0123456789ABCDEF";
		len = ft_putnbr_base(va_arg(args, unsigned int), base);
	}
	else if (format[i] == '%')
		len = ft_putchar((int) '%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	if (write(1, 0, 0) != 0)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
		{
			len++;
			ft_putchar(format[i]);
		}
		else if (format[i] == '%' && format[i + 1])
		{
			len = len + ft_conversion(format, i + 1, args, len);
			i++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
