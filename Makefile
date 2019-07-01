# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fokrober <fokrober@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/01 02:08:35 by fokrober          #+#    #+#              #
#    Updated: 2019/07/01 02:38:25 by fokrober         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = 	main.c srcs/fillit.c srcs/ft_strlenx.c srcs/isfull.c srcs/printab.c \
		srcs/set_tetris.c srcs/shift_tetris.c srcs/sort.c srcs/valid_file.c \
		srcs/valid_line.c srcs/valid_tetrimino.c
OBJ = $(SRC:%.c=%.o)
FLAG = -Wall -Wextra -Werror
LIBFT = libft/libft.a

all:	$(NAME)

$(NAME):
	make -C libft
	gcc $(FLAG) $(SRC) $(LIBFT) -o $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
	make -C libft re