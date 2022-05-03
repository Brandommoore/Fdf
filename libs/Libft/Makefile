# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 17:00:13 by mcordoba          #+#    #+#              #
#    Updated: 2022/03/15 14:51:52 by mcordoba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_isalpha.c \
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
	ft_strrchr.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_atoi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_calloc.c \
	ft_strtrim.c \
	ft_split.c \
	ft_strmapi.c \
	ft_itoa.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	get_next_line.c \
	get_next_line_check.c \
	get_next_line_w.c \
	get_next_line_w_map.c \
	get_next_line_wl.c \
	get_next_line_h.c \
	get_next_line_utils.c

BONUS_SRC = ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c
	

NAME = libft.a

SEARCH = libft.h

OBJ = $(SRC:%.c=%.o)

BONUS_OBJ = $(BONUS_SRC:%.c=%.o)

AR = ar rcs

RM = rm -f

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(SEARCH)
	$(AR) $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ) $(SEARCH)
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus