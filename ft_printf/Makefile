# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 09:32:22 by blakehal          #+#    #+#              #
#    Updated: 2022/11/19 09:24:17 by blakehal         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR              = ar rcs

SRCS = 	ft_printf.c \
		ft_putchar.c \
		ft_putnbr_base.c \
		ft_putptr_base.c \
		ft_putstr.c \
		ft_putunbr_base.c \
		ft_putnbr.c


OBJS    = ${SRCS:.c=.o}

HEADER = ft_printf.h

all :	${NAME}

%.o: %.c ${HEADER} Makefile
	${CC} ${CFLAGS} -I. -c $< -o $@


${NAME} : ${OBJS} ${HEADER}
	${AR} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean :        clean
	${RM} ${NAME}

re :            fclean all

.PHONY:         all clean fclean re
