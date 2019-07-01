/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:41:36 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/30 23:05:27 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

int		chk_line(char *line, int *nblines, int *tab, int **all_tetris)
{
	int		ret;

	if (nblines[0] % 5)
	{
		if ((ret = valid_line(line, tab, nblines)) < 0)
			return (ret);
		nblines[1]++;
	}
	else if (*line == '\n')
	{
		if (isfull(tab, 4) != TAB_FULL || !valid_tetrimino(tab))
			return (NOT_TETRIS);
		if (!(save_tetris(tab, all_tetris)))
			return (ALLOC_ERR);
		ft_bzero(tab, 4 * sizeof(int));
	}
	else
		return (INV_LINE);
	return (1);
}

int		chk_buff(char *buf, int ret, int **all_tetris)
{
	char	*line;
	int		i;
	int		tab[4];
	int		nblines[2];

	ft_bzero(tab, sizeof(tab));
	ft_bzero(nblines, sizeof(nblines));
	i = 0;
	while (i < ret)
	{
		nblines[0]++;
		line = &buf[i];
		if (chk_line(line, nblines, tab, all_tetris) != 1)
			return (0);
		nblines[0] % 5 == 0 ? i++ : (i += 5);
	}
	if (!(save_tetris(tab, all_tetris)))
		return (ALLOC_ERR);
	return ((i >= ret) && (!(nblines[1] % 4) && valid_tetrimino(tab)));
}

int		valid_file(int fd, int **all_tetris)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	ft_bzero(buf, sizeof(buf));
	ret = read(fd, buf, BUF_SIZE);
	buf[BUF_SIZE] = '\n';
	if (ret > BUF_SIZE || ret <= 0)
		return (INV_FILE);
	if (chk_buff(buf, ret, all_tetris) > 0)
		return (VALID_FILE);
	del_all(all_tetris);
	return (INV_FILE);
}
