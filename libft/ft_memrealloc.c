/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 07:03:31 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/27 01:20:00 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void *content, size_t cur_size, size_t des_size)
{
	void	*content_cpy;

	content_cpy = content;
	content = ft_memalloc(des_size);
	if (!content)
	{
		content = content_cpy;
		return (content);
	}
	content = ft_memcpy(content, content_cpy, cur_size);
	ft_memdel(&content_cpy);
	return (content);
}
