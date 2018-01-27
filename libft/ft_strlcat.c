/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 23:29:42 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/04 16:37:06 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_cpy;
	const char	*src_cpy;
	size_t		n;
	size_t		dlen;

	dst_cpy = dst;
	src_cpy = src;
	n = size;
	while (n-- != 0 && *dst_cpy != '\0')
		dst_cpy++;
	dlen = dst_cpy - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src_cpy));
	while (*src_cpy != '\0')
	{
		if (n != 1)
		{
			*dst_cpy++ = *src_cpy;
			n--;
		}
		src_cpy++;
	}
	*dst_cpy = '\0';
	return (dlen + (src_cpy - src));
}
