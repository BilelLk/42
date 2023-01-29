/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:17:00 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/29 14:17:00 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main ()
{
	fork();
	printf("Hello Warudo\n");
	fork();
	printf("Ca va warudo ?\n");
	return (0);
}
