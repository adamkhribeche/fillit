/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <fokrober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:26:23 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/30 20:21:05 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

void	ft_swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a = *a - *b;
}

int		sort(int *tab, int n)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	if (n < 2)
		return (1);
	while (j < (n - 1))
	{
		if (tab[j] > tab[j + 1])
		{
			ft_swap(&tab[j], &tab[j + 1]);
			i++;
		}
		j++;
	}
	if (!i)
		return (1);
	return (sort(tab, n - 1));
}
