/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 15:45:02 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/30 20:21:16 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

int		is_connection(int side, int *tab)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (side == tab[i])
			break ;
		i++;
	}
	return (!(i == 4));
}

int		valid_tetrimino(int *tab)
{
	int i;
	int connection;

	i = 0;
	connection = 0;
	while (i < 4)
	{
		connection += is_connection(tab[i] - 4, tab);
		connection += is_connection(tab[i] + 4, tab);
		connection += is_connection(tab[i] - 1, tab);
		connection += is_connection(tab[i] + 1, tab);
		i++;
	}
	return (connection == 6 || connection == 8);
}
