/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:23:08 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/11 20:20:28 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *sf;

	if (!(sf = ft_strnew(sizeof(*s1) * ft_strlen(s1))))
		return (NULL);
	sf = ft_strcpy(sf, s1);
	return (sf);
}
