# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/31 19:38:26 by blakehal          #+#    #+#              #
#    Updated: 2023/01/25 16:40:25 by blakehal         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NONE=\033[0m
GREEN=\033[32m
GRAY=\033[2;37m
CURSIVE=\033[3m
RED_0=\033[31m
RED_1=\033[1m

OBJS_DIR		= OBJ/

SRCS			= ft_parsing.c \
				  ft_calloc.c \
				  ft_is_not_sorted.c \
				  ft_strlen.c \
				  ft_split.c \
				  ft_substr.c \
				  ft_push.c \
				  ft_reverse.c \
				  ft_rotate.c \
				  ft_swap.c \
				  ft_sort_little.c \
				  ft_utils1.c \
				  ft_utils2.c \
				  ft_utils_solve3.c \
				  ft_bzero.c 
OBJS_SRCS		= $(addprefix ${OBJS_DIR}, $(SRCS:.c=.o))

SRCS_PS			= ft_push_swap.c ft_utils_solve1.c ft_utils_solve2.c
OBJS_PS			= $(addprefix ${OBJS_DIR}, $(SRCS_PS:.c=.o))
NAME			= push_swap

BON				= ft_bonus_checker.c ft_bonus_get_next_line.c ft_bonus_get_next_line_utils.c
OBJS_BON		= $(addprefix ${OBJS_DIR}, $(BON:.c=.o))
NAME_BON		= checker

HEAD			= ft_push_swap.h
CC				= cc
RM				= rm -rf
FLAGS			= -Wall -Wextra -Werror -g3

all:			${NAME}

$(OBJS_DIR)%.o: %.c ${HEAD}
				mkdir -p ${OBJS_DIR}
				${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

${NAME}:		${OBJS_SRCS} ${OBJS_PS}
				mkdir -p ${OBJS_DIR}
				@echo "${GREEN}Beginning of Compilation😊${NONE}"
				cd .progress_bar/ && ./heavy_work.sh
				${CC} ${FLAGS} ${OBJS_SRCS} ${OBJS_PS} -o ${NAME}

bonus:			${OBJS_SRCS} ${OBJS_BON}
				mkdir -p ${OBJS_DIR}
				@echo "${GREEN}Beginning of Bonus Compilation😊${NONE}"
				cd .progress_bar/ && ./heavy_work_bonus.sh
				${CC} ${FLAGS} ${OBJS_SRCS} ${OBJS_BON} -o ${NAME_BON}

clean:
				@echo "${RED_0}Removing ${RED_1}objects files...😔"
				$(RM) ${OBJS_DIR}

fclean:			clean
				@echo "         and executable file...😔${NONE}"
				${RM} ${NAME} ${NAME_BON}
				cd .progress_bar/ && ./heavy_work_invert.sh

re:				fclean all

.SILENT : 		clean fclean $(NAME) re $(SRCS:.c=.o) dir all bonus

.PHONY:			all clean fclean re bonus dir target