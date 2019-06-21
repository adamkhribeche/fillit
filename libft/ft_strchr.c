/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:55:41 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/10 01:43:36 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!(char)c)
		return ((char*)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
	}
	return (NULL);
}
