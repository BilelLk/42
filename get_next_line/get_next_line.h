/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:18:13 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/26 08:46:58 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *tmp);
char	*ft_strjoin(char *line, char *buff);
char	*ft_implement(char *tmp);
char	*ft_clean(char *tmp);
int		ft_strrchr(char *s, char c);
size_t	ft_strlen(const char *str);

#endif