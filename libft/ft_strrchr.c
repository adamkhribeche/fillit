/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <fokrober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:23:32 by fokrober          #+#    #+#             */
/*   Updated: 2019/04/23 15:12:52 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	if (c && ft_strchr(s, c))
	{
		if (ft_strrchr((1 + ft_strchr(s, c)), c))
			return (ft_strrchr(1 + ft_strchr(s, c), c));
		else
			return (ft_strchr(s, c));
	}
	return (ft_strchr(s, c));
}
