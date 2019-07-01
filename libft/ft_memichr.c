/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 22:11:42 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/02 22:41:54 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_memichr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((ssize_t)i);
		i++;
	}
	return (-1);
}
