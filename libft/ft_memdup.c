/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:05:06 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/26 00:07:36 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *cont, size_t size)
{
	void	*dupped;

	if (size == 0 || !cont)
		return (NULL);
	dupped = ft_memalloc(size);
	if (!dupped)
		return (NULL);
	dupped = ft_memcpy(dupped, cont, size);
	return (dupped);
}
