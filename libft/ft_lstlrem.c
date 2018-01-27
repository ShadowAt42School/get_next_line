/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlrem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 00:40:03 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/24 02:35:09 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlrem(t_list *head)
{
	t_list	*cursor;
	t_list	*back;

	if (head == NULL)
		return (NULL);
	cursor = head;
	back = NULL;
	while (cursor->next != NULL)
	{
		back = cursor;
		cursor = cursor->next;
	}
	if (back != NULL)
		back->next = NULL;
	if (cursor == head)
		head = NULL;
	ft_memdel((void**)&cursor);
	return (head);
}
