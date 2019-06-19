/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 20:22:44 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/10 01:59:23 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ishere(const char *s, const char *c)
{
	while (*c)
		if (*(s++) != *(c++))
			return (0);
	return (1);
}

char			*ft_strstr(const char *s, const char *tofind)
{
	if (!*tofind)
		return ((char*)s);
	while (*s)
	{
		if (ft_ishere(s, tofind))
			return ((char*)s);
		s++;
	}
	return (NULL);
}
