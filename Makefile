# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 20:29:36 by marvin            #+#    #+#              #
#    Updated: 2022/01/26 20:40:45 by mcordoba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.c \
		

NAME = fdf

SEARCH = fdf.h

OBJ = $(SRC:%.c=%.o)

RM = rm -f

CC = gcc

CFLAGS = -fsanitize=address -g3 -Wall -Werror -Wextra

CFNAME = -o $(NAME)

all: $(NAME)

$(NAME): $(OBJ) $(SEARCH)
	@make -s -C libs/Libft
	$(CC) $(CFLAGS) $(OBJ) -L libs/Libft $(CFNAME)

clean:
	@make clean -C libs/Libft
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f libs/Libft/libft.a
	$(RM) $(NAME) $(OBJ)

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus
