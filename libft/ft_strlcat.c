/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:06:06 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/10 00:54:02 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = ft_strlen(dst);
	if (size >= ft_strlen(dst) + ft_strlen(src) + 1)
	{
		ft_strcat(dst, src);
		return (i + ft_strlen(src));
	}
	else if (size >= ft_strlen(dst) + 1)
	{
		ft_strncat(dst, src, size - ft_strlen(dst) - 1);
		return (i + ft_strlen(src));
	}
	else
		return (ft_strlen(src) + size);
}
