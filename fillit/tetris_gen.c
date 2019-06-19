/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:28:42 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/19 01:05:46 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

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

int		main(void)
{
	char	buf[21];
	int		i;

	i = 0;
	buf[20] = '\0';
	while (i < 20)// generer 20 tetrimino
	{
		tetris_gen(buf);
		if (ft_check_input(buf))
		{
			printf("%s\n", buf);
			i++;
		}
	}
	return (0);
}
