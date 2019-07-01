/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:29:21 by fokrober          #+#    #+#             */
/*   Updated: 2019/05/02 22:46:48 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush(t_list *elm, t_list *new)
{
	if (!elm && !new)
		return (NULL);
	while (elm->next)
		elm = elm->next;
	return ((elm->next = new));
}
