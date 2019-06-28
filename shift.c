/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:47:44 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/28 14:47:47 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
