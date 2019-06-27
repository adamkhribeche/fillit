/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:55:55 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/27 19:14:08 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H


#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"


typedef struct		s_coordinates
{
	int		x;
	int		y;
}					t_coordinates;

typedef struct		s_tetrimino
{
	t_coordinates		tab[4];
	int					order;
}				t_tetrimino;

typedef struct		s_board
{
	char	**board;
	int		size;
}					t_board;

int			ft_check_input(char *buff);
int			ft_receive_in_tab(int fd, t_tetrimino *tetri_tab);
void		ft_display_in_small_board(t_tetrimino *tetris_tab, int nbr_of_tetris);
void		ft_shift_all_tetriminos(t_tetrimino *tetris_tab, int nbr_of_tetris);
int			ft_minx(t_tetrimino tetrimino);
int			ft_miny(t_tetrimino tetrimino);
void		ft_subtract_from_coord(t_tetrimino *tetrimino, int i, int j);
t_board*	ft_creat_new_board(int size);
void		ft_display_board(t_board board);
int			ft_fill_is_done(t_tetrimino *tetris_tab, int nbr_of_tetris, int order, t_board *board);
void		ft_free_board(t_board **board);
int			ft_add_tetri_to_board(t_tetrimino tetrimino, t_board *board, int position);
void		ft_rm_tetri_from_board(t_board *board, t_tetrimino tetrimino, int position);

#endif
