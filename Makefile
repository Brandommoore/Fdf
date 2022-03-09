# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 20:29:36 by marvin            #+#    #+#              #
#    Updated: 2022/03/09 18:47:43 by mcordoba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.c \
		utils/freedom.c \
		utils/ft_putstr.c \
		utils/errmanag/errmanag.c \
		utils/events/close_clear.c \
		utils/print_in_window/bresen_alg.c \
		utils/print_in_window/isometric.c \
		utils/print_in_window/shift_map.c \
		utils/print_in_window/mlx_put_pixel.c \
		utils/print_in_window/print_lines.c \
		utils/print_in_window/print_map.c \
		utils/read_map/open_map.c \
		utils/read_map/map_size.c \
		utils/read_map/fill_map_struct.c \
		utils/read_map/str_to_color.c
		

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
