/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:19:29 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/12 01:30:58 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;

	i = -1;
	while (++i < n)
	{
		if (((unsigned char*)src)[i] != (unsigned char)c)
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		else
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			return (dst + i + 1);
		}
	}
	return (NULL);
}
