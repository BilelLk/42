# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 13:58:54 by blakehal          #+#    #+#              #
#    Updated: 2023/03/07 17:52:24 by blakehal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

INC			=	pipex.h
INC_DIR		=	./includes/

HEADERS		= $(addprefix $(INC_DIR), $(INC))

SRC_DIR		=	./sources/
SRC			=	pipex.c			\
				process.c			\
				free_utils.c		\
				files_utils.c		\
				parsing.c			\
				process_utils.c	\


LIBFT_DIR	=	libft/
LIBFT_A		=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	libft

OBJ_DIR		=	build/
OBJ			=	$(SRC:%.c=$(OBJ_DIR)%.o)

CC			=	gcc
CC_FLAGS	=	-Wextra -Werror -Wall -g3

all: build_libft $(NAME)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
		mkdir -p $(@D)
		$(CC) $(CC_FLAGS) -I$(INC_DIR) -I$(LIBFT_INC) -c $< -o $@

$(NAME): $(LIBFT_A) $(OBJ)
		$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT_A) -o $@

build_libft: $(LIBFT_DIR)
		$(MAKE) -C $(LIBFT_DIR)

clean:
		$(MAKE) -C libft fclean
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re build_libft