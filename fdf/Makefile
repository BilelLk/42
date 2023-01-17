# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 14:20:07 by blakehal          #+#    #+#              #
#    Updated: 2023/01/17 18:28:09 by blakehal         ###   ########lyon.fr    #
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
SRC			=	main.c 			\
				read_file.c		\
				draw.c 			\
				event.c			\
				param.c			\
				utils.c			\
				free.c			\

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
		echo "${GREEN}Beginning of Compilation😊${NONE}"
		cd .progress_bar/ && ./heavy_work.sh
		$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT_A) $(MLX_A) $(MLX_FLAG) -o $@

build_libft:
		$(MAKE) -s -C $(LIBFT_DIR)

$(MLX_A): $(MLX_DIR)
		$(MAKE) -s -C $(MLX_DIR)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBFT_DIR) $(HEADERS)
		mkdir -p $(@D)
		$(CC) $(CC_FLAGS) -I$(INC_DIR) -I$(LIBFT_INC) -I$(MLX_DIR) -c $< -o $@

clean:
		echo "${RED_0}Removing ${RED_1}objects files...😔"
		$(MAKE) clean -C $(LIBFT_DIR)
		$(MAKE) clean -C $(MLX_DIR)
		rm -rf $(OBJ_DIR)

fclean: clean
		echo "         and executable file...😔${NONE}"
		cd .progress_bar/ && ./heavy_work_invert.sh
		rm -rf $(NAME)
		$(MAKE) fclean -s -C $(LIBFT_DIR)

re: fclean all

.SILENT : clean fclean $(NAME) re $(SRCS:.c=.o) dir all bonus build_libft

.PHONY: all clean fclean re build_libft