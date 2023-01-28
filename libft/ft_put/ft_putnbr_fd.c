/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:27:27 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/12 15:31:16 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n_bis;

	n_bis = n;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n_bis = -n;
	}
	if (n_bis > 9)
	{
		ft_putnbr_fd((n_bis / 10), fd);
		ft_putnbr_fd((n_bis % 10), fd);
	}
	if (n_bis <= 9)
		ft_putchar_fd((n_bis + '0'), fd);
}
