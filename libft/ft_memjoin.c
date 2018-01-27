/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 23:05:00 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/26 03:20:37 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *sh, const void *sn, size_t shl, size_t snh)
{
	if (!sh || !sn || (shl == 0 && snh == 0) || snh == 0)
		return (NULL);
	sh = ft_memrealloc(sh, shl, shl + snh);
	if (!sh)
		return (sh);
	ft_memcpy(sh + shl, sn, snh);
	return (sh);
}
