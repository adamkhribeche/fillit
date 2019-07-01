/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <fokrober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:14:41 by fokrober          #+#    #+#             */
/*   Updated: 2019/04/23 16:37:02 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s2;

	if ((s2 = ft_memalloc(ft_strlen(s1) + 1)))
		return ((s2 = (char*)ft_memcpy(s2, s1, ft_strlen(s1) + 1)));
	else
		return (NULL);
}
