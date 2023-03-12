# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 18:27:18 by blakehal          #+#    #+#              #
#    Updated: 2023/03/11 19:00:12 by blakehal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY_DIR = pipex_mandatory/
BONUS_DIR = pipex_bonus/

all:
	$(MAKE) -C $(MANDATORY_DIR)

bonus:
	$(MAKE) -C $(BONUS_DIR)

clean:
		$(MAKE) -C $(MANDATORY_DIR) fclean
		$(MAKE) -C $(BONUS_DIR) fclean

fclean: clean

re: fclean all

.PHONY: all clean fclean re build_libft