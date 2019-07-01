/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:48:52 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/29 02:21:45 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fillit.h"

int		blocs_gen(int *tab)
{
	tab[0] = arc4random_uniform(17);
	tab[1] = arc4random_uniform(17);
	tab[2] = arc4random_uniform(17);
	tab[3] = arc4random_uniform(17);
	return (valid_tetrimino(tab));
}

void	tetris_gen(char *tetris)
{
	int			tab[4];
	int			ret;
	int			i;

	ret = 0;
	i = 0;
	while (!ret)
		ret = blocs_gen(tab);
	ret = 0;
	while (ret < 16)
	{
		if (tab[i] == ret + 1)
		{
			tetris[ret] = '#';
			i++;
		}
		else
			tetris[ret] = '.';
		ret++;
	}
}

void	print_tetris(char *tetris, int j)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		ft_putchar(tetris[i]);
		if (!((i + 1) % 4))
		{
			if (j != 26)
				ft_putchar('\n');
			else
				ft_putchar('\n');
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	char	tetris[16];
	int		nbtetris;
	int		i;

	i = 1;
	if (ac != 2)
		return (0);
	nbtetris = ft_atoi(av[1]);
	while (i < nbtetris)
	{
		ft_putnbr(i);
		ft_putchar('\n');
		tetris_gen(tetris);
		print_tetris(tetris, i);
		i++;
		if (i != nbtetris)
			ft_putchar('\n');
	}
	return (0);
}
