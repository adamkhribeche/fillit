/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 19:33:31 by nkhribec          #+#    #+#             */
/*   Updated: 2019/07/01 23:25:36 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int ac, char **av)
{
	int				fd;
	t_tetrimino		tetris_tab[26];
	int				nbr_of_tetris;

	if (ac != 2)
		ft_putstr("usage: fillit file_name\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		if (!(nbr_of_tetris = ft_receive_in_tab(fd, tetris_tab)))
			ft_putstr("error\n");
		else
			ft_display_in_small_board(tetris_tab, nbr_of_tetris);
		close(fd);
	}
	return (0);
}
