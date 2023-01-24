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

NAME		   :=   libft.a

INC            :=   libft.h
INC_DIR        :=   includes/

HEADERS        :=   $(addprefix $(INC_DIR), $(INC))

SRC_DIR        :=   sources/
SRC				:= 	ft_isalpha.c \
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

OBJ_DIR        :=    build/
OBJ            :=    $(SRC:%.c=$(OBJ_DIR)%.o)

# Compiler options
CC            :=    cc
CC_FLAGS      :=    -Wextra -Werror -Wall #-fsanitize=address -g3
DEBUG_FLAG    :=    -ggdb3

# define standard colors
_END        :=    \x1b[0m
_BOLD       :=    \x1b[1m
_UNDER      :=    \x1b[4m
_REV        :=    \x1b[7m
_GREY       :=    \x1b[30m
_RED        :=    \x1b[31m
_GREEN      :=    \x1b[32m
_YELLOW     :=    \x1b[33m
_BLUE       :=    \x1b[34m
_PURPLE     :=    \x1b[35m
_CYAN       :=    \x1b[36m
_WHITE      :=    \x1b[37m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -I$(INC_DIR) -c $< -o $@

# clean commands
clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
