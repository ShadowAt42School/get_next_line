/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:18:28 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/05 23:31:20 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*current;

	if (!alst || !del)
		return ;
	current = *alst;
	while (current)
	{
		next = current->next;
		ft_lstdelone(&current, del);
		free(current);
		current = next;
	}
	*alst = NULL;
}
