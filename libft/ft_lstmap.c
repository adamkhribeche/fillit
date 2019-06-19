/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:02:35 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/11 21:22:26 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *begin;

	if (!lst || !f)
		return (NULL);
	begin = (*f)(lst);
	while (lst->next)
	{
		new = (*f)(lst->next);
		ft_lst_add_end(begin, new);
		lst = lst->next;
	}
	return (begin);
}
