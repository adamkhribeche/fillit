/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 01:20:54 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/30 23:06:20 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

void	shift_tetris_top(int *tab, int size)
{
	int		valx[2][4];
	int		val[2];
	int		i;

	set_shift(tab, valx, size);
	val[0] = valx[0][0] * size;
	val[1] = valx[1][0];
	i = 0;
	while (i < 4)
	{
		tab[i] -= val[0] + val[1];
		i++;
	}
}

void	shift_tetris_right(int *tab, int j, int val)
{
	int i;

	i = 0;
	if (j < val)
	{
		while (i < 4)
		{
			tab[i] += 1;
			i++;
		}
	}
}

void	shift_tetris_down(int *tab, int size, int n)
{
	int i;

	i = 0;
	if (n)
	{
		while (i < 4)
		{
			tab[i] += n * size;
			i++;
		}
	}
}

void	shift(int *tab, int size)
{
	int x;
	int	i;

	x = size - 4;
	i = 0;
	while (i < 4)
	{
		tab[i] += x * ((tab[i] - 1) / 4);
		i++;
	}
}

void	shift_all_tetris_to(int **all_tetris, int size)
{
	int	i;

	i = 0;
	if (size != 4)
		shift_all_tetris_to(all_tetris, 4);
	while (i < 26 && all_tetris[i])
	{
		if (size != 4)
			shift(all_tetris[i], size);
		shift_tetris_top(all_tetris[i], size);
		i++;
	}
}
