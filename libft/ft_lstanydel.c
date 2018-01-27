/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstanydel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 00:43:04 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/25 21:46:26 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstanydel(t_list *head, t_list *nd)
{
	t_list	*cursor;
	t_list	*tmp;

	if (nd == head)
		head = ft_lstfrem(&head);
	else if (nd->next == NULL)
		head = ft_lstlrem(head);
	else
	{
		cursor = head;
		while (cursor != NULL)
		{
			if (cursor->next == nd)
				break ;
			cursor = cursor->next;
		}
		if (cursor != NULL)
		{
			tmp = cursor->next;
			cursor->next = tmp->next;
			tmp->next = NULL;
			ft_memdel((void**)&tmp);
		}
	}
	return (head);
}
