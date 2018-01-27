/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:21:18 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/26 06:34:10 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_node;

	new_node = (t_list *)ft_memalloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	if (!content)
	{
		new_node->content = NULL;
		new_node->content_size = 0;
		new_node->next = NULL;
	}
	else
	{
		new_node->content = ft_memalloc(content_size);
		if (!new_node)
			return (NULL);
		new_node->content = ft_memcpy(new_node->content, content, content_size);
		new_node->content_size = content_size;
		new_node->next = NULL;
	}
	return (new_node);
}
