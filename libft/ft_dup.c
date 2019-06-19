/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:22:00 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/11 20:23:46 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dup(void const *content, size_t content_size)
{
	void		*new;
	size_t		i;

	if (!(new = ft_memalloc(content_size)))
		return (NULL);
	i = 0;
	while (i < content_size)
	{
		((char*)new)[i] = ((char*)content)[i];
		i++;
	}
	return (new);
}
