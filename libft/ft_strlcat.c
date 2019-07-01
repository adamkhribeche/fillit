/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <fokrober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 19:10:15 by fokrober          #+#    #+#             */
/*   Updated: 2019/04/23 15:14:44 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	len;
	size_t	j;

	len = ft_strlen(s1);
	if (size <= len)
		return (size + ft_strlen(s2));
	j = 0;
	size -= len + 1;
	while (s2[j] && j < size)
	{
		s1[len + j] = s2[j];
		j++;
	}
	s1[len + j] = '\0';
	return (len + ft_strlen(s2));
}
