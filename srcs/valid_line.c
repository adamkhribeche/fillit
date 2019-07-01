/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 15:56:08 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/29 02:16:11 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

int		valid_line(char *line, int *tab, int *nblines)
{
	static int	pos = 1;
	int			i[2];

	if (ft_strlenx(line) != 4)
		return (INV_LINE);
	i[0] = 0;
	i[1] = 0;
	if (!(nblines[1] % 4))
		pos = 1;
	while (i[0] < 4 && line[i[0]] != '\n')
	{
		if (line[i[0]] == '.')
			pos++;
		else if (line[i[0]] == '#')
		{
			if ((i[1] = isfull(tab, 4)) == TAB_FULL)
				return (NOT_TETRIS);
			tab[i[1]] = pos;
			pos++;
		}
		else
			return (INV_LINE);
		i[0]++;
	}
	return (1);
}
