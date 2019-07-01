/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 03:14:42 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/03 04:32:01 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *s1, void const *s2,
		size_t s_size, size_t b_size)
{
	char	*tmp;

	tmp = NULL;
	if (!s2 || !b_size)
	{
		if (!s1 || !s_size)
			return (ft_memalloc(1));
	}
	if (!s1 || !s_size)
		return (ft_memdupz(s2, b_size));
	tmp = ft_memalloc(s_size + b_size + 1);
	(void)ft_memcpy(tmp, s1, s_size);
	(void)ft_memcpy(&tmp[s_size], s2, b_size);
	return (tmp);
}
