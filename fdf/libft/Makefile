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

NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

AR              = ar rcs

OBJS_DIR		= OBJ/

SRCS = 	ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   get_next_line.c \
	   get_next_line_utils.c \

SRCS_BONUS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

OBJS    = $(addprefix ${OBJS_DIR}, $(SRCS:.c=.o))

OBJS_B = $(addprefix ${OBJS_DIR}, ${SRCS_BONUS:.c=.o})

HEADER = libft.h

all :	${NAME}

$(OBJS_DIR)%.o: %.c ${HEADER}
				mkdir -p ${OBJS_DIR}
				${CC} ${FLAGS} -I. -c $< -o $@


${NAME} : 		${OBJS} ${HEADER}
				mkdir -p ${OBJS_DIR}
				@echo "${GREEN}Beginning of Compilation😊"
				cd .progress_bar/ && ./heavy_work.sh
				${AR} ${NAME} ${OBJS}

bonus: 			${OBJS_B} ${HEADER}
				mkdir -p ${OBJS_DIR}
				@echo "${GREEN}Beginning of Bonus Compilation😊"
				cd .progress_bar/ && ./heavy_work_bonus.sh
				${AR} ${NAME} ${OBJS_B}

clean:
				@echo "${RED_0}Removing ${RED_1}objects files...😔"
				${RM} ${OBJS_DIR}

fclean :        clean
				@echo "         and executable file...😔${NONE}"
				${RM} ${NAME}
				cd .progress_bar/ && ./heavy_work_invert.sh

re :            fclean all

.SILENT : 		clean fclean $(NAME) re $(SRCS:.c=.o) dir all bonus

.PHONY:         all clean fclean re bonus
