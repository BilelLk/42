# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 09:32:22 by blakehal          #+#    #+#              #
#    Updated: 2023/01/11 13:41:41 by blakehal         ###   ########lyon.fr    #
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

CC				=	gcc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror
NAME			=	libft.a
LIBC			=	ar rcs
DIR_INCS		=	.
DIR_BUILD		=	.build/
OBJS			=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS))
DEPS			=	$(patsubst %.c, $(DIR_BUILD)%.d, $(SRCS))
DEPS_FLAGS		=	-MMD -MP

all:		$(NAME)

$(NAME):	$(OBJS)
			$(LIBC) $(NAME) $(OBJS)
			echo "${GREEN}Beginning of Compilation😊${NONE}"
			cd .progress_bar/ && ./heavy_work.sh

clean:
			$(RM) $(DIR_BUILD)
			echo "${RED_0}Removing ${RED_1}objects files...😔"

fclean:		clean
			$(RM) $(NAME)
			echo "         and executable file...😔${NONE}"
			cd .progress_bar/ && ./heavy_work_invert.sh

re:			fclean
			make all

-include $(DEPS)

$(DIR_BUILD)%.o : %.c
			mkdir -p $(shell dirname $@)
			$(CC) $(CFLAGS) $(DEPS_FLAGS) $(DIR_INCS:%=-I %) -c $< -o $@

.SILENT :

.PHONY: all clean fclean re

