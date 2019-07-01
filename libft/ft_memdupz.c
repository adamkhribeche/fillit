/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdupz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 03:06:35 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/03 00:37:17 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdupz(const void *src, size_t n)
{
	void	*tmp;

	if (n && (tmp = ft_memalloc(n + 1)))
		return (ft_memcpy(tmp, src, n));
	return (ft_memalloc(1));
}
