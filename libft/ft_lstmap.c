/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 00:20:46 by fokrober          #+#    #+#             */
/*   Updated: 2019/05/02 22:48:09 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;

	if (!(list = f(lst)) || !lst || !f)
		return (NULL);
	while (lst->next)
	{
		ft_lstpush(list, f(lst->next));
		lst = lst->next;
	}
	return (list);
}
