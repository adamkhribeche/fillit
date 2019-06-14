/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:54:17 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/14 17:09:33 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_board(char ***board, int size)
{
	int i;

	i = 0;
	while (size--)
		free((*board)[i++]);
	free(*board);
	*board = NULL;
}
//-------------------
int		ft_add_tetri_to_board(t_tetrimino tetrimino, char **board, int size)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size) 
		{
			k = -1;
			while (++k < 4)
			{
				if ((tetrimino.tab[k].x + j < size) && (tetrimino.tab[k].y + i < size) &&
						board[i + tetrimino.tab[k].y][j + tetrimino.tab[k].x] == '.')
					continue;
				else
					break;
			}
			if (k == 4)
			{
				k = -1;
				while (++k < 4)
					board[i + tetrimino.tab[k].y][j + tetrimino.tab[k].x] = 64 + tetrimino.order;
				return (1);
			}
		}
	}
	return (0);
}
//------------------
/*int		ft_fill_is_done(t_tetrimino *tetris_tab, int nbr_of_tetris, int order, char ***board, int size)
{
	static int	*is_order_exist = (int *)malloc(sizeof(int) * nbr_of_tetris);

	if (!nbr_of_tetris)
		return (1);
	while (nbr_of_tetris)
	{
		if (!is_order_exist[order] && ft_add_tetri_to_board(tetris_tab[order], *board, size))
		{
			is_order_exist[order] = 1;
			nbr_of_tetris--;
			if (ft_fill_is_done(tetris_tab, nbr_of_tetris, order + 1, board, size))
				return (1);
		}
	}
	is_order_exist[order] = 0;
	nbr_of_tetris--;
	return (0);
}*/
//---------------------------------
/*void	ft_display_in_small_board(t_tetrimino *tetris_tab, int nbr_of_tetris)
{
	char	**board;
	int		size;

	size = 2;
	ft_shift_tetrimino(tetris_tab, nbr_of_tetris);
	ft_creat_new_board(&board, size);
	while (!(ft_fill_is_done(tetris_tab, nbr_of_tetris, 0, &board, size))) // in order that can change the value of size
	{
		ft_free_board(&board, size);
		ft_creat_new_board(&board, size + 1);
	}
	ft_display_board(board, size);
}*/
//---------------------------
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
//--------------------------------
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
//--------------------------------
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
//---------------------------------------
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
//----------------------------------------
void	ft_creat_new_board(char ***board, int size)//sinc I want to assigne a value to **board
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
//----------------------------------------
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
//---------------------------------------------
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
//-----------------------------------------------
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
	//int				i = 0;
	//int				j;
	char			**board;

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
			
			ft_shift_tetrimino(tetris_tab, nbr_of_tetris);
			ft_creat_new_board(&board, 6);
			ft_add_tetri_to_board(tetris_tab[0], board, 6);
			ft_add_tetri_to_board(tetris_tab[1], board, 6);
			ft_add_tetri_to_board(tetris_tab[2], board, 6);
			ft_add_tetri_to_board(tetris_tab[3], board, 6);
			ft_display_board(board, 6);


			/*printf("----------avant---------\n");
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
			}*/
		}

	}
	return (0);
}

/*system("clear");
usleep(122);*/
