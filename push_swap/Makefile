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

NAME		=	push_swap

INC			=	ft_push_swap.h
INC_DIR		=	./includes/

HEADERS		= $(addprefix $(INC_DIR), $(INC))

SRC_DIR		=	./sources/
SRC			=	ft_parsing.c \
				ft_is_not_sorted.c \
				ft_push.c \
				ft_reverse.c \
				ft_rotate.c \
				ft_swap.c \
				ft_sort_little.c \
				ft_utils1.c \
				ft_utils2.c \
				ft_utils_solve3.c \
				ft_push_swap.c \
				ft_utils_solve1.c \
				ft_utils_solve2.c


LIBFT_DIR	=	libft/
LIBFT_A		=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	libft

OBJ_DIR		=	build/
OBJ			=	$(SRC:%.c=$(OBJ_DIR)%.o)

CC			=	gcc -g3
CC_FLAGS	=	-Wextra -Werror -Wall

all: build_libft $(NAME)

$(NAME): $(LIBFT_A) $(OBJ)
		$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT_A) -o $@
		echo "${GREEN}Beginning of Compilation😊${NONE}"
		cd .progress_bar/ && ./heavy_work.sh

build_libft: $(LIBFT_DIR)
		$(MAKE) -C $(LIBFT_DIR)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
		mkdir -p $(@D)
		$(CC) $(CC_FLAGS) -I$(INC_DIR) -I$(LIBFT_INC) -c $< -o $@

clean:
		$(MAKE) clean -C $(LIBFT_DIR)
		rm -rf $(OBJ_DIR)
		echo "${RED_0}Removing ${RED_1}objects files...😔"

fclean: clean
		rm -rf $(NAME)
		$(MAKE) fclean -s -C $(LIBFT_DIR)
		echo "         and executable file...😔${NONE}"
		cd .progress_bar/ && ./heavy_work_invert.sh

re: fclean all

.SILENT :

.PHONY: all clean fclean re build_libft