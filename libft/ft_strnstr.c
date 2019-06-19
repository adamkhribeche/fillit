/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:00:25 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/10 18:40:42 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ishere(const char *s, const char *c, size_t max)
{
	while (*c && max--)
		if (*s++ != *c++)
			return (0);
	if (!*c)
		return (1);
	return (0);
}

char			*ft_strnstr(const char *s, const char *tofind, size_t len)
{
	char	*tmp;

	tmp = (char *)s;
	if (!*tofind)
		return (tmp);
	while (*tmp && len)
	{
		if (ft_ishere(tmp, tofind, len))
			return (tmp);
		tmp++;
		len--;
	}
	return (NULL);
}
