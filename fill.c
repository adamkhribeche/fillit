/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:24:06 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/28 16:25:21 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_rm_tetri_from_board(t_board *board, t_tetrimino tetrimino,\
		int position)
{
	int		k;
	int		i;
	int		j;

	i = position / board->size;
	j = position % board->size;
	k = -1;
	while (++k < 4)
		board->board[i + tetrimino.tab[k].y][j + tetrimino.tab[k].x] = '.';
}

int		ft_add_tetri_to_board(t_tetrimino tetrimino, t_board *board,\
		int position)
{
	int		i;
	int		j;
	int		k;

	i = position / board->size;
	j = position % board->size;
	k = -1;
	while (++k < 4)
	{
		if ((tetrimino.tab[k].x + j < board->size) &&
		(tetrimino.tab[k].y + i < board->size) &&
		board->board[i + tetrimino.tab[k].y][j + tetrimino.tab[k].x] == '.')
			continue ;
		else
			return (0);
	}
	k = -1;
	while (++k < 4)
		board->board[i + tetrimino.tab[k].y][j + tetrimino.tab[k].x] =\
		65 + tetrimino.order;
	return (1);
}

int		ft_fill_is_done(t_tetrimino *tetris_tab, int nbr_of_tetris,\
		int order, t_board *board)
{
	int		pt_nbr;
	int		pt_max;

	pt_nbr = 0;
	if (order == nbr_of_tetris)
		return (1);
	pt_max = board->size * board->size;
	while (pt_nbr < (pt_max - 3))
	{
		if (ft_add_tetri_to_board(tetris_tab[order], board, pt_nbr))
		{
			if (ft_fill_is_done(tetris_tab, nbr_of_tetris, order + 1, board))
				return (1);
			ft_rm_tetri_from_board(board, tetris_tab[order], pt_nbr);
		}
		pt_nbr++;
	}
	return (0);
}

void	ft_display_in_small_board(t_tetrimino *tetris_tab, int nbr_of_tetris)
{
	t_board		*board;
	int			size;

	size = 2;
	while (size * size < nbr_of_tetris * 4)
		size++;
	ft_shift_all_tetriminos(tetris_tab, nbr_of_tetris);
	board = ft_creat_new_board(size);
	while (!(ft_fill_is_done(tetris_tab, nbr_of_tetris, 0, board)))
	{
		ft_free_board(&board);
		board = ft_creat_new_board(++size);
	}
	ft_display_board(*board);
}
