/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:03:16 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/19 11:31:16 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putstr(char *s);
int	ft_putnbr(int nbr);
int	ft_putptr_base(unsigned long long nbr, char *base);
int	ft_putunbr_base(unsigned int nbr, char *base);
int	ft_printf(const char *format, ...);

#endif
