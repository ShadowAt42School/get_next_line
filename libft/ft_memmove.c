/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 20:41:51 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/02 23:06:06 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *destc;
	unsigned char *srcc;

	srcc = (unsigned char *)src;
	destc = (unsigned char *)dest;
	if (destc == srcc)
		return (dest);
	if (srcc < destc)
	{
		destc += n - 1;
		srcc += n - 1;
		while (n--)
			*destc-- = *srcc--;
	}
	else
	{
		while (n--)
			*destc++ = *srcc++;
	}
	return (dest);
}
