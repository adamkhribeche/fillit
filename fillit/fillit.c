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

int		check_file(int fd, char **tab)
{
	int i;
	int j;
	int max_line;

	i = 0;
	max_line = (5 * 26) - 1;
	while ((get_next_line(fd, &tab[i]) == 1) && (i < (max_line)))
	{
		printf("%s\n", tab[i]);
		if (((i + 1) % 5) == 0)
		{
			if (tab[i][0] != '\0')
				return (0);
		}
		else
		{
			if ((ft_strlen(tab[i]) != 4))
				return (0);
			j = 0;
			while (tab[i][j])
			{
				if (!ft_strchr("#.", tab[i][j]))
					return (0);
				j++;
			}
		}
		i++;
	}
	if (i >= ((5 * 26) - 1))
		return (0);
	return (1);
}

/*int	check_tetriminos(char **tab)
{

}*/

int		main(int ac, char **av)
{
	int fd;
	char **tab;

	tab = (char**)ft_memalloc(sizeof(*tab) * 27);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (check_file(fd, tab))
		{
			ft_putstr("file is valid\n");
			if (check_tetriminos(tab))

		}
		else 
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: fillit file_name\n");
	return (1);
}
