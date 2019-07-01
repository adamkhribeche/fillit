/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:44:01 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/30 22:48:02 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fillit.h"

int		main(int ac, char **av)
{
	int		**all_tetris;
	int		nbtetris_fd[2];

	if (ac == 2)
	{
		if (!(all_tetris = (int**)ft_memalloc(27 * sizeof(int*))))
			return (1);
		nbtetris_fd[1] = open(av[1], O_RDONLY);
		ft_bzero(all_tetris, sizeof(all_tetris));
		if (valid_file(nbtetris_fd[1], all_tetris) == 1)
		{
			nbtetris_fd[0] = 0;
			while (all_tetris[nbtetris_fd[0]] && nbtetris_fd[0] < 26)
				nbtetris_fd[0]++;
			fill(all_tetris, better_size(2, nbtetris_fd[0]), nbtetris_fd[0]);
		}
		else
			ft_putstr("error\n");
		close(nbtetris_fd[1]);
	}
	else
		ft_putstr("usage : ./fillit file\n");
	return (0);
}

int		better_size(int size, int nbtetris)
{
	while (size * size < nbtetris * 4)
		size++;
	return (size);
}
