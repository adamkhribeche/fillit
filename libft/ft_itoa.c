/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 21:57:29 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/10 22:15:29 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_leni(int n)
{
	int count;

	count = 1;
	if (n < 0)
		count++;
	while (n / 10 != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			leni;
	size_t			until;
	unsigned int	nb;

	leni = ft_leni(n);
	if (!(str = ft_strnew(ft_leni(n))))
		return (NULL);
	until = 0;
	if (n < 0)
	{
		nb = -n;
		*str = '-';
		until++;
	}
	else
		nb = n;
	while (leni > until)
	{
		str[leni - 1] = nb % 10 + '0';
		nb = nb / 10;
		leni--;
	}
	return (str);
}
