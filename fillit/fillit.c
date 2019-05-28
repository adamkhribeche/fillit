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

int		ft_receive_in_lst(int fd, t_list *begin)
{
	int		i;
	int		line_nbr;
	int		n;
	int		max_tetriminos;
	char	*tmp;
	int		retur_get;
	t_list		*new;

	n = 1;
	max_tetriminos =  26;
	retur_get = 1;
	while (retur_get == 1 && n < max_tetriminos)
	{
		begin->content = (t_tetrimino*)ft_memalloc(sizeof(t_tetrimino));
		line_nbr = 1;
		while (k <= 5 && (retur_get = get_next_line(fd, &tmp)) == 1)
		{
			//test begin
			if ((k % 5) == 0)
			{
				if (ft_strlen(tmp) != 0)
					return (0);
			}
			else
			{
				if ((ft_strlen(tmp) != 4))
					return (0);
				i = 0;
				while (tmp[i])
				{
					if (!ft_strchr("#.", tmp[i]))
						return (0);
					i++;
				}
				//test end
				ft_strcat(((t_tetrimino*)(begin->content))->tab, tmp);
				ft_strdel(&tmp);
			}
			line_nbr++;
		}
		if (retur_get == 0 && k == 5)
			return (1);
		else if (k == 6)
		{
			new = (t_list*)ft_memalloc(sizeof(*new));
			ft_lst_add_end(begin, new);
			begin = begin->next;
		}
		else
			return (0);
		n++;
	}
	if (n >= max_tetriminos)
		return (0);
	return (1);
}

/*int	check_tetriminos(char **tab)
  {

  }*/

int		main(int ac, char **av)
{
	int				fd;
	t_list 			*begin;

	begin = ft_lstnew(NULL, 0);
	if (ac != 2)
		ft_putstr("usage: fillit file_name\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		if (!ft_receive_in_lst(fd, begin))
			ft_putstr("error\n");
		else 
		{
			ft_putstr("file is valid\n");
			printf("%c\n", ((t_tetrimino*)(begin->next->next->next->content))->tab[15]);

			//if (check_tetriminos(tab))

		}
	}
	return (1);
}
