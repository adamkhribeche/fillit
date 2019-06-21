/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:14:55 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/04 15:32:20 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	int				index;

	index = 0;
	tmp = (unsigned char *)b;
	while (len != 0)
	{
		*tmp = (unsigned char)c;
		len--;
		tmp++;
		index++;
	}
	return ((void *)(tmp - index));
}
