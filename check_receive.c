/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_receive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:31:20 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/28 14:31:24 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int		ft_receive_in_tab(int fd, t_tetrimino *tetri_tab)
{
	char		buff[22];
	ssize_t		ret;
	int			order;
	int			ret_prev;

	order = -1;
	ret_prev = 0;
	while ((ret = read(fd, buff, 21)) >= 20)
	{
		ret_prev = ret;
		order++;
		if (order > 25)
			return (0);
		buff[ret] = '\0';
		if (!ft_check_input(buff))
			return (0);
		ft_add_to_tab(tetri_tab, order, buff);
	}
	if (ret != 0 || ret_prev != 20)
		return (0);
	return (order + 1);
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
			tetri_tab[order].order = order;
			i++;
		}
	}
}
