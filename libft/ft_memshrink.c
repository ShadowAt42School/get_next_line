/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memshrink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 03:05:01 by maghayev          #+#    #+#             */
/*   Updated: 2018/02/02 04:21:39 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memshrink(void *area, void *start, size_t len)
{
	void	*new_area;

	new_area = NULL;
	new_area = ft_memalloc(len > 0 ? len : 1);
	if (!new_area)
		return (NULL);
	if (len > 0)
		new_area = ft_memcpy(new_area, start, len);
	ft_memdel(&area);
	return (new_area);
}
