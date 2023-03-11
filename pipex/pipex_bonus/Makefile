# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 13:58:54 by blakehal          #+#    #+#              #
#    Updated: 2023/03/11 17:14:18 by blakehal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

INC			=	pipex_bonus.h
INC_DIR		=	./includes/

HEADERS		= $(addprefix $(INC_DIR), $(INC))

SRC_DIR		=	./sources/
SRC			=	pipex_bonus.c			\
				process_bonus.c			\
				free_utils_bonus.c		\
				files_utils_bonus.c		\
				parsing_bonus.c			\
				process_utils_bonus.c	\
				here_doc_bonus.c		\


LIBFT_DIR	=	libft/
LIBFT_A		=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	libft

OBJ_DIR		=	build/
OBJ			=	$(SRC:%.c=$(OBJ_DIR)%.o)

CC			=	gcc
CC_FLAGS	=	-Wextra -Werror -Wall

all: $(NAME)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS) $(LIBFT_A) $(LIBFT_DIR)libft.h
		mkdir -p $(@D)
		$(CC) $(CC_FLAGS) -I$(INC_DIR) -I$(LIBFT_INC) -c $< -o $@

$(NAME): $(OBJ)
		$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT_A) -o $@

${LIBFT_A}: FORCE
	$(MAKE) -C ${LIBFT_DIR}
	
FORCE:
	
build_libft: $(LIBFT_DIR)
		$(MAKE) -C $(LIBFT_DIR)

clean:
		$(MAKE) -C libft fclean
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re build_libft