/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 18:06:49 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/11 22:05:51 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		index;

	if (!s || !f || !(new = ft_strnew(sizeof(*s) * ft_strlen(s))))
		return (NULL);
	index = 0;
	while (*s)
	{
		*new = (*f)(*s);
		s++;
		new++;
		index++;
	}
	return (new - index);
}
