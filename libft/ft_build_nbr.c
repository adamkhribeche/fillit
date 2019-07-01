/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <fokrober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:44:19 by fokrober          #+#    #+#             */
/*   Updated: 2019/04/23 14:28:46 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_build_nbr(const char *s)
{
	int		i;
	char	*result;

	result = ft_strnew(0);
	i = 0;
	if (!s)
		return ((char*)s);
	if (ft_isdigit(s[i + 1]) || ft_isdigit(s[i]))
	{
		if (s[i] == '-')
		{
			result = ft_push_char(result, s[i]);
			i++;
		}
		else if (s[i] == '+')
			i++;
		while (ft_isdigit(s[i]))
		{
			result = ft_push_char(result, s[i]);
			i++;
		}
	}
	return (result);
}
