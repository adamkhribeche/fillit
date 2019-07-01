/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <fokrober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:55:04 by fokrober          #+#    #+#             */
/*   Updated: 2019/05/04 15:29:13 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_push_nbr(char *s, int n)
{
	if (n == MIN_INT)
	{
		s = ft_push_nbr(s, -214748364);
		n = 8;
	}
	if (n < 0)
	{
		s = ft_push_char(s, '-');
		n *= -1;
	}
	if (n < 10)
		s = ft_push_char(s, '0' + n);
	else if (n >= 10)
	{
		s = ft_push_nbr(s, n / 10);
		s = ft_push_nbr(s, n % 10);
	}
	return (s);
}
