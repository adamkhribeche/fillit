/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:35:13 by fokrober          #+#    #+#             */
/*   Updated: 2019/05/04 21:37:14 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && ft_strchr(" \t\v\f\r\n", s[i]))
		i++;
	if (!s[i])
		return (ft_strnew(0));
	len = ft_strlen(s) - 1;
	while (s[len] && ft_strchr(" \t\v\f\r\n", s[len]))
		len--;
	return (ft_strsub(s, i, len - i + 1));
}
