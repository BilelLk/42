# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 09:32:22 by blakehal          #+#    #+#              #
#    Updated: 2023/03/11 14:23:04 by blakehal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NONE=\033[0m
GREEN=\033[32m
GRAY=\033[2;37m
CURSIVE=\033[3m
RED_0=\033[31m
RED_1=\033[1m

SRCS = 	ft_is/ft_isalpha.c			\
		ft_is/ft_isdigit.c			\
		ft_is/ft_isalnum.c			\
		ft_is/ft_isascii.c			\
		ft_is/ft_isprint.c			\
		ft_malloc/ft_bzero.c		\
		ft_malloc/ft_calloc.c		\
		ft_malloc/ft_split.c		\
		ft_malloc/ft_substr.c		\
		ft_mem/ft_memset.c			\
		ft_mem/ft_memcpy.c			\
		ft_mem/ft_memmove.c			\
		ft_mem/ft_memchr.c			\
		ft_mem/ft_memcmp.c			\
		ft_put/ft_putchar_fd.c		\
		ft_put/ft_putstr_fd.c		\
		ft_put/ft_putendl_fd.c		\
		ft_put/ft_putnbr_fd.c		\
		ft_put/ft_putchar.c			\
		ft_put/ft_putnbr_base.c		\
		ft_put/ft_putptr_base.c		\
		ft_put/ft_putstr.c			\
		ft_put/ft_putunbr_base.c	\
		ft_put/ft_putnbr.c			\
		ft_str/ft_strlen.c			\
		ft_str/ft_strlcpy.c			\
		ft_str/ft_strlcat.c			\
		ft_str/ft_strnstr.c			\
		ft_str/ft_strjoin.c			\
		ft_str/ft_strtrim.c			\
		ft_str/ft_strmapi.c			\
		ft_str/ft_striteri.c		\
		ft_str/ft_strchr.c			\
		ft_str/ft_strrchr.c			\
		ft_str/ft_strncmp.c			\
		ft_str/ft_strdup.c			\
		ft_str/ft_strndup.c			\
		ft_str/ft_strncpy.c			\
		gnl/get_next_line.c			\
		gnl/get_next_line_utils.c	\
		ft_lst/ft_lstadd_front.c	\
		ft_lst/ft_lstsize.c			\
		ft_lst/ft_lstlast.c			\
		ft_lst/ft_lstadd_back.c		\
		ft_lst/ft_lstdelone.c		\
		ft_lst/ft_lstclear.c		\
		ft_lst/ft_lstiter.c			\
		ft_lst/ft_lstmap.c			\
		ft_lst/ft_lstnew.c			\
		ft_toupper.c				\
		ft_tolower.c				\
		ft_atoi.c					\
		ft_itoa.c					\
		ft_printf/ft_printf.c		\

CC				=	gcc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror -g3
NAME			=	libft.a
LIBC			=	ar rcs
DIR_INCS		=	.
DIR_BUILD		=	.build/
OBJS			=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS))
DEPS			=	$(patsubst %.c, $(DIR_BUILD)%.d, $(SRCS))

all:		$(NAME)

$(NAME):	$(OBJS)
			$(LIBC) $(NAME) $(OBJS)

clean:
			$(RM) $(DIR_BUILD)

fclean:		clean
			$(RM) $(NAME)

re:			fclean
			make all

-include $(DEPS)

$(DIR_BUILD)%.o : %.c libft.h
			mkdir -p $(shell dirname $@)
			$(CC) $(CFLAGS) $(DIR_INCS:%=-I %) -c $< -o $@

.PHONY: all clean fclean re

