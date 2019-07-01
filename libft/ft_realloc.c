/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:50:32 by fokrober          #+#    #+#             */
/*   Updated: 2019/05/21 21:58:28 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t oldsize, size_t newsize)
{
	void	*p;

	if (newsize == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
		return (ft_memalloc(newsize));
	else if (newsize <= oldsize)
		return (ptr);
	else
	{
		p = malloc(newsize);
		if (p)
		{
			ft_memcpy(p, ptr, oldsize);
			ft_bzero(ptr, oldsize);
			ft_memdel(&ptr);
		}
		return (p);
	}
}
