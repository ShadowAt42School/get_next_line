/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfrem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 00:33:35 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/25 21:46:29 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstfrem(t_list **head)
{
	t_list	*front;

	if (head == NULL)
		return (NULL);
	front = *head;
	*head = (*head)->next;
	front->next = NULL;
	if (front == *head)
		head = NULL;
	ft_memdel((void**)&front);
	return (*head);
}
