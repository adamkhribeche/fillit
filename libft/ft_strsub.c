/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 18:48:10 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/10 21:48:05 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		index;

	if (!s || !(new = ft_strnew(len)))
		return (NULL);
	index = 0;
	while (start--)
		s++;
	while (len--)
	{
		*(new++) = *(s++);
		index++;
	}
	*new = '\0';
	return (new - index);
}
