# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 20:29:36 by marvin            #+#    #+#              #
#    Updated: 2022/01/31 21:41:01 by mcordoba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.c \
		

NAME = fdf

SEARCH = fdf.h

OBJ = $(SRC:%.c=%.o)

RM = rm -f

CC = gcc

CFLAGS = -I. -fsanitize=address -g3 -Wall -Werror -Wextra -Imlx

CFNAME = -o $(NAME)

LIBFT_SRC = libs/Libft/libft.a

MINILIBX_SRC = libs/minilibx_macos/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(SEARCH)
	@make -C libs/Libft
	@make -C libs/minilibx_macos
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_SRC) $(MINILIBX_SRC) -lmlx -framework OpenGL -framework AppKit -L. $(CFNAME)

clean:
	@make clean -C libs/Libft
	@make clean -C libs/minilibx_macos
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f libs/Libft/libft.a
	@rm -f libs/minilibx_macos/libmlx.a
	$(RM) $(NAME) $(OBJ)

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus
