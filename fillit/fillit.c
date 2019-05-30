/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:54:17 by nkhribec          #+#    #+#             */
/*   Updated: 2019/05/18 19:06:12 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	ft_replace_hashtag(char *tab, int order)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '#')
			tab[i] = 65 + order;
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

int		ft_receive_in_lst(int fd, t_list **begin)
{
	char		buff[22];
	t_list		*new;
	ssize_t		ret;
	int			order;

	order = -1;
	//ft_bzero(buff, 22);
	while ((ret = read(fd, buff, 21)) >= 20)
	{
		buff[ret] = '\0';
		if (!ft_check_input(buff))
			return (0);
		if (!(*begin))
			*begin = ft_lstnew(NULL, 0);
		else
		{
			new = (t_list*)ft_memalloc(sizeof(t_list));
			ft_lstadd(begin, new);
		}
		order++;
		ft_replace_hashtag(buff, order);
		(*begin)->content = ft_memalloc(sizeof(t_tetrimino));
		((t_tetrimino*)((*begin)->content))->tab = ft_strdup(buff);
	}
	if (ret == 0 && buff[20] != '\0')
		return (0);

	return (order + 1);
}

int		main(int ac, char **av)
{
	int				fd;
	t_list 			*begin;
	int				nbr_of_tetris;
	char			**board;
	int				i = 0;
	int				j;

	board = (char**) ft_memalloc(4 * sizeof(char*));
	while (i < 4)
	{
		board[i] = (char*) ft_memalloc(4 * sizeof(char));
		i++;
	}

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			board[i][j] = '.';
			j++;
		}
		i++;
	}
	ft_putchar(board[2][2]);

	if (ac != 2)
		ft_putstr("usage: fillit file_name\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		begin = NULL;
		if (!(nbr_of_tetris = ft_receive_in_lst(fd, &begin)))
			ft_putstr("error\n");
		else 
		{
			//printf("%d\n", nbr_of_tetris);
			ft_putstr("file is valid\n");
			//printf("%s\n", ((t_tetrimino*)(begin->content))->tab);
			ft_display_board(board, 4);
		}
	}
	return (1);
}
