/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:19:07 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/28 14:19:25 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free_board(t_board **board)
{
	int		i;

	i = 0;
	while ((*board)->size--)
		free((*board)->board[i++]);
	free((*board)->board);
	free(*board);
	*board = NULL;
}

t_board	*ft_creat_new_board(int size)
{
	int			i;
	int			j;
	t_board		*board;

	board = (t_board*)ft_memalloc(sizeof(*board));
	board->board = (char**)ft_memalloc(size * sizeof(char*));
	i = 0;
	while (i < size)
	{
		board->board[i] = (char*)ft_memalloc(size * sizeof(char));
		j = 0;
		while (j < size)
		{
			board->board[i][j] = '.';
			j++;
		}
		i++;
	}
	board->size = size;
	return (board);
}

void	ft_display_board(t_board board)
{
	int		i;
	int		j;

	i = 0;
	while (i < board.size)
	{
		j = 0;
		while (j < board.size)
		{
			ft_putchar(board.board[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
