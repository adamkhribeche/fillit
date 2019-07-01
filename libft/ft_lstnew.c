/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:45:27 by fokrober          #+#    #+#             */
/*   Updated: 2019/05/03 00:50:33 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elm;

	if (!(elm = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	else if (!content)
		content_size = 0;
	ft_lstset(&elm, content, content_size);
	elm->next = NULL;
	return (elm);
}
