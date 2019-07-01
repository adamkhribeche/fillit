/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atonbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <fokrober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:44:01 by fokrober          #+#    #+#             */
/*   Updated: 2019/04/23 14:15:22 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atonbr(char *s)
{
	int		n;
	int		signe;

	n = 0;
	signe = 1;
	if (*s == '-')
	{
		signe = -1;
		s++;
	}
	while (ft_todigit(*s) != -1)
	{
		n = (10 * n) + ft_todigit(*s++);
	}
	return (n * signe);
}
