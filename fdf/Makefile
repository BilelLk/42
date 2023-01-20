# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 14:20:07 by blakehal          #+#    #+#              #
#    Updated: 2023/01/18 11:31:43 by blakehal         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NONE=\033[0m
GREEN=\033[32m
GRAY=\033[2;37m
CURSIVE=\033[3m
RED_0=\033[31m
RED_1=\033[1m

NAME		=	fdf

INC			=	fdf.h
INC_DIR		=	./

HEADERS		= $(addprefix $(INC_DIR), $(INC))

SRC_DIR		=	./
SRC			=	fdf.c 			\
				read_file.c		\
				draw.c 			\
#				ft_dealkey.c	\
#				ft_key_hooks.c	\
#				ft_utils.c		\
#				ft_free.c			\

LIBFT_DIR	=	libft/
LIBFT_A		=	$(LIBFT_DIR)libft.a

OBJ_DIR		=	build/
OBJ			=	$(SRC:%.c=$(OBJ_DIR)%.o)

CC			=	cc
CC_FLAGS	=	-Wextra -Werror -Wall

MLX_DIR	=	mlx/
MLX_A	=	$(MLX_DIR)libmlx.a
MLX_FLAG = -lm -framework OpenGL -framework AppKit

all: build_libft $(NAME)

$(NAME): $(OBJ) $(LIBFT_A) $(MLX_A)
		$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT_A) $(MLX_A) $(MLX_FLAG) -o $@
		echo "${GREEN}Beginning of Compilation😊${NONE}"
		cd .progress_bar/ && ./heavy_work.sh

build_libft:
		$(MAKE) -s -C $(LIBFT_DIR)

$(MLX_A): $(MLX_DIR)
		$(MAKE) -s -C $(MLX_DIR)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBFT_DIR) $(HEADERS)
		mkdir -p $(@D)
		$(CC) $(CC_FLAGS) -I$(INC_DIR) -I$(LIBFT_INC) -I$(MLX_DIR) -c $< -o $@

clean:
		$(MAKE) clean -C $(LIBFT_DIR)
		$(MAKE) clean -C $(MLX_DIR)
		rm -rf $(OBJ_DIR)
		echo "${RED_0}Removing ${RED_1}objects files...😔"

fclean: clean
		rm -rf $(NAME)
		$(MAKE) fclean -s -C $(LIBFT_DIR)
		echo "         and executable file...😔${NONE}"
		cd .progress_bar/ && ./heavy_work_invert.sh

re: fclean all

.SILENT : clean fclean $(NAME) re $(SRCS:.c=.o) dir all bonus build_libft

.PHONY: all clean fclean re build_libft