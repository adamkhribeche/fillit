/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 23:33:48 by fokrober          #+#    #+#             */
/*   Updated: 2019/04/23 00:16:08 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_bsize(const void *ptr)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (!((unsigned char*)ptr))
		return (0);
	while (*((unsigned char*)ptr + i))
	{
		len += sizeof(ptr[i]);
		if (!*((unsigned char*)ptr + i + 1))
			len++;
		i++;
	}
	return (len);
}
