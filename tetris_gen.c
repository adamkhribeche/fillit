/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:28:42 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/27 17:58:52 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

int		ft_check_buff(char *buff, int i, int *contact_point)
{
	if ((i + 1) % 5 == 0)
	{
		if (buff[i] != '\n')
			return (0);
	}
	else
	{
		if (buff[i] == '.')
			contact_point[1] += 1;
		else if (buff[i] == '#')
		{
			if (i > 0 && buff[i - 1] == '#')
				contact_point[0] += 1;
			if (i < 19 && buff[i + 1] == '#')
				contact_point[0] += 1;
			if (i < 14 && buff[i + 5] == '#')
				contact_point[0] += 1;
			if (i > 4 && buff[i - 5] == '#')
				contact_point[0] += 1;
		}
		else
			return (0);
	}
	return (1);
}
int		ft_check_input(char *buff)
{
	int		i;
	int		contact_point[2];

	contact_point[0] = 0;
	contact_point[1] = 0;
	i = -1;
	while (++i < 20)
		if (!ft_check_buff(buff, i, contact_point))
			return (0);
	return ((contact_point[1] == 12) &&\
			(contact_point[0] == 6 || contact_point[0] == 8) &&\
			(buff[20] == '\n' || buff[20] == '\0'));
}

int my_atoi(char *s)
{
	int res;

	res = 0;
	while (*s)
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res);
}
int		tetris_gen(char *buf)// genere un seul tetrimino
{
	int	c;
	int	i;
	int	nb;

	i = 0;
	nb = 1;
	while (i < 20)
	{
		if ((i + 1) % 5 == 0)
		{
			buf[i++] = '\n';
			continue ;
		}
		if (nb < 5 && (c = arc4random_uniform(2)))// le nbr max de # dans un tetrim c'est 4 + arc4random genere des nbr aleatoirs soit 0 soit 1
		{
			buf[i] = '#';
			nb++;
		}
		else
			buf[i] = '.';
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	char	buf[21];
	int		i;
	int		n;

	i = 0;
	buf[20] = '\0';
	n = my_atoi(av[ac - 1]);
	while (i < n)// generer ft_atoi(av[ac - 1]) tetrimino
	{
		tetris_gen(buf);
		if (ft_check_input(buf))
		{
			if (i == n - 1)
				printf("%s", buf);
			else
				printf("%s\n", buf);
			i++;
		}
	}
	return (0);
}
