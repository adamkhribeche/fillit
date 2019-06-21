/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:22:50 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/10 18:37:01 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int index;

	index = 0;
	while (*s1)
	{
		s1++;
		index++;
	}
	while (*s2 && n--)
	{
		*s1 = *s2;
		s1++;
		s2++;
		index++;
	}
	*s1 = '\0';
	return (s1 - index);
}
