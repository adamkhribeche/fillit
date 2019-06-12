/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:54:17 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/12 22:08:30 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		ft_minx(t_tetrimino tetrimino)
{
	int min;
	int i;

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
	int min;
	int i;

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
	int index;

	index = -1;
	while (++index < 4)
	{
		(*tetrimino).tab[index].x -= i;
		(*tetrimino).tab[index].y -= j;
	}
}

void	ft_shift_tetrimino(t_tetrimino *tetris_tab, int nbr_of_tetris)
{
	int i;
	int j;
	int index;

	index = 0;
	while (nbr_of_tetris--)
	{
		i = ft_minx(tetris_tab[index]);
		j = ft_miny(tetris_tab[index]);
		ft_subtract_from_coord(&tetris_tab[index], i, j);
		index++;
	}
}
/*void	ft_display_in_small_board(t_tetrimino *tetris_tab, int nbr_of_tetris)
  {
  ft_shift_tetrimino(t_tetrimino *tetris_tab, int nbr_of_tetris);
  }*/

void	ft_creat_new_board(char ***board, int size)
{
	int		i;
	int		j;

	*board = (char**) ft_memalloc(size * sizeof(char*));
	i = 0;
	while (i < size)
	{
		(*board)[i] = (char*) ft_memalloc(size * sizeof(char));
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			(*board)[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	ft_display_board(char **board, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(board[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		ft_check_input(char *buff)
{
	int		i;
	int		contact;
	int		point;

	contact = 0;
	point = 0;
	i = -1;
	if (!buff)
		return (0);
	while (++i < 20)
	{
		if ((i + 1) % 5 == 0)
		{
			if (buff[i] != '\n')
				return (0);
		}
		else
		{
			if (buff[i] == '.')
				point++;
			else if (buff[i] == '#')
			{
				if (i > 0 && buff[i - 1] == '#')
					contact++;
				if (i < 19 && buff[i + 1] == '#')
					contact++;
				if (i < 14 && buff[i + 5] == '#')
					contact++;
				if (i > 4 && buff[i - 5] == '#')
					contact++;
			}
			else
				return (0);
		}
	}
	return (point == 12 && (contact == 6 || contact == 8) && (buff[20] == '\n' || buff[20] == '\0'));
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
			tetri_tab[order].order = order + 1;
			i++;
		}
	}
}

int		ft_receive_in_tab(int fd, t_tetrimino *tetri_tab)
{
	char			buff[22];
	ssize_t			ret;
	int				order;

	order = -1;
	while ((ret = read(fd, buff, 21)) >= 20)
	{
		order++;
		if ((order + 1) > 26)
			return (0);
		buff[ret] = '\0';
		if (!ft_check_input(buff))
			return (0);
		ft_add_to_tab(tetri_tab, order, buff);
	}
	if (ret == 0 && buff[20] != '\0') //gerer le dernier ligne
		return (0);
	return (order + 1);
}

int		main(int ac, char **av)
{
	int				fd;
	t_tetrimino		tetris_tab[26];
	int				nbr_of_tetris;
	int				i = 0;
	int				j;

	if (ac != 2)
		ft_putstr("usage: fillit file_name\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		if (!(nbr_of_tetris = ft_receive_in_tab(fd, tetris_tab)))
			ft_putstr("error\n");
		else 
		{
			//ft_display_in_small_board(tetrimino *tetris_tab, nbr_of_tetris);
			printf("----------avant---------\n");
			while (i < 5)
			{
				j = 0;
				while (j < 4)
				{
					printf("%d , %d\n", tetris_tab[i].tab[j].x , tetris_tab[i].tab[j].y);
					j++;
				}
				printf("--order = %d\n", tetris_tab[i].order);
				ft_putchar('\n');
				i++;
			}

			ft_shift_tetrimino(tetris_tab, nbr_of_tetris);
			printf("----------apres----nbroftetris---%d--\n", nbr_of_tetris);
			i = 0;
			while (i < 5)
			{
				j = 0;
				while (j < 4)
				{
					printf("%d , %d\n", tetris_tab[i].tab[j].x , tetris_tab[i].tab[j].y);
					j++;
				}
				printf("--order = %d\n", tetris_tab[i].order);
				ft_putchar('\n');
				i++;
			}
		}

	}
	return (0);
}
