/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 21:14:12 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/11 20:25:18 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_countw(const char *s, char c)
{
	int count;

	count = 0;
	if (*s != c)
	{
		count++;
		s++;
	}
	while (*s)
	{
		if (*s != c && *(s - 1) == c)
			count++;
		s++;
		while (*s == c)
			s++;
	}
	return (count);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;
	int				i;
	int				j;
	size_t			len;
	unsigned int	start;

	if (!s || !(tab = (char**)ft_memalloc(sizeof(s) * (ft_countw(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while ((s[i] == c) && s[i])
		i++;
	while (s[i])
	{
		start = i;
		len = 0;
		while (s[i + len] != c && s[i + len])
			len++;
		i = i + len;
		tab[j++] = ft_strsub(s, start, len);
		while (s[i] == c && s[i])
			i++;
	}
	return (tab);
}
