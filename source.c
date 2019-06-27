/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:09:01 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/27 18:47:26 by nkhribec         ###   ########.fr       */
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
			system("clear");
			ft_display_board(*board);
			usleep(1000);
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

int		ft_minx(t_tetrimino tetrimino)
{
	int		min;
	int		i;

	min = 3;
	i = -1;
	while (++i < 4)
	{
		if (tetrimino.tab[i].x < min)
			min = tetrimino.tab[i].x;
	}
	return (min);
}

int		ft_miny(t_tetrimino tetrimino)
{
	int		min;
	int		i;

	min = 3;
	i = -1;
	while (++i < 4)
	{
		if (tetrimino.tab[i].y < min)
			min = tetrimino.tab[i].y;
	}
	return (min);
}

void	ft_subtract_from_coord(t_tetrimino *tetrimino, int i, int j)
{
	int		index;

	index = -1;
	while (++index < 4)
	{
		(*tetrimino).tab[index].x -= i;
		(*tetrimino).tab[index].y -= j;
	}
}

void	ft_shift_all_tetriminos(t_tetrimino *tetris_tab, int nbr_of_tetris)
{
	int		i;
	int		j;
	int		index;

	index = 0;
	while (nbr_of_tetris--)
	{
		j = ft_minx(tetris_tab[index]);
		i = ft_miny(tetris_tab[index]);
		ft_subtract_from_coord(&tetris_tab[index], j, i);
		index++;
	}
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

int		ft_check_buff(char *buff, int i, int *contact_point)
{
	if ((i + 1) % 5 == 0)
	{
		if (buff[i] != '\n')
			return (0);
	}
	else
	{
		if (buff[i] == '.')
			contact_point[1] += 1;
		else if (buff[i] == '#')
		{
			if (i > 0 && buff[i - 1] == '#')
				contact_point[0] += 1;
			if (i < 19 && buff[i + 1] == '#')
				contact_point[0] += 1;
			if (i < 14 && buff[i + 5] == '#')
				contact_point[0] += 1;
			if (i > 4 && buff[i - 5] == '#')
				contact_point[0] += 1;
		}
		else
			return (0);
	}
	return (1);
}

int		ft_check_input(char *buff)
{
	int		i;
	int		contact_point[2];

	contact_point[0] = 0;
	contact_point[1] = 0;
	i = -1;
	while (++i < 20)
		if (!ft_check_buff(buff, i, contact_point))
			return (0);
	return ((contact_point[1] == 12) &&\
		(contact_point[0] == 6 || contact_point[0] == 8) &&\
			(buff[20] == '\n' || buff[20] == '\0'));
}

void	ft_add_to_tab(t_tetrimino *tetri_tab, int order, char *buff)
{
	int		position;
	int		i;

	i = 0;
	position = -1;
	while (buff[++position])
	{
		if (buff[position] == '#')
		{
			tetri_tab[order].tab[i].x = position % 5;
			tetri_tab[order].tab[i].y = position / 5;
			tetri_tab[order].order = order;
			i++;
		}
	}
}

int		ft_receive_in_tab(int fd, t_tetrimino *tetri_tab)
{
	char		buff[22];
	ssize_t		ret;
	int			order;
	int			ret_prev;

	order = -1;
	ret_prev = 0;
	while ((ret = read(fd, buff, 21)) >= 20)
	{
		ret_prev = ret;
		order++;
		if (order > 25)
			return (0);
		buff[ret] = '\0';
		if (!ft_check_input(buff))
			return (0);
		ft_add_to_tab(tetri_tab, order, buff);
	}
	if (ret != 0 || ret_prev != 20)
		return (0);
	return (order + 1);
}
