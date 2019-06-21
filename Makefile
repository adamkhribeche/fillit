# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 19:50:14 by nkhribec          #+#    #+#              #
#    Updated: 2019/06/19 20:52:01 by nkhribec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = source.c main.c
OBJ = source.o main.o
FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C libft re
	gcc $(FLAG) -c $(SRC)
	gcc $(FLAG) -o $(NAME) $(OBJ) libft/libft.a

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
