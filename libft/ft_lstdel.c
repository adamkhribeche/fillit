/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 23:11:20 by fokrober          #+#    #+#             */
/*   Updated: 2019/05/02 00:07:32 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *li_elmt;

	while (*alst)
	{
		li_elmt = *alst;
		*alst = li_elmt->next;
		ft_lstdelone(&li_elmt, del);
	}
}
