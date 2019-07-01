/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <fokrober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:10:03 by fokrober          #+#    #+#             */
/*   Updated: 2019/04/23 18:45:02 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(needle);
	if (len == 0)
		return ((char*)haystack);
	i = 0;
	while (haystack[i] && (i + len <= size) &&
		!ft_strnequ(&haystack[i], needle, len))
		i++;
	if ((i + len <= size) && ft_strnequ(&haystack[i], needle, len))
		return (((char*)haystack) + i);
	return (NULL);
}
