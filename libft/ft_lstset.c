/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 00:43:26 by fokrober          #+#    #+#             */
/*   Updated: 2019/05/03 00:50:37 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstset(t_list **elm, void const *content, size_t content_size)
{
	(*elm)->content = ft_memdup(content, content_size);
	(*elm)->content_size = content_size;
	return ((*elm)->content);
}
