/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <fokrober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:51:39 by fokrober          #+#    #+#             */
/*   Updated: 2019/05/04 20:12:13 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (n && ((unsigned char*)src)[i] != (unsigned char)c)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		i++;
		n--;
	}
	if (n && ((unsigned char*)src)[i] == (unsigned char)c)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		return (&dst[i + 1]);
	}
	return (NULL);
}
