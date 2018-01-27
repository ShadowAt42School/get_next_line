/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 01:07:26 by maghayev          #+#    #+#             */
/*   Updated: 2017/12/06 00:51:17 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int		i;

	i = 0;
	while (len - i > 0)
	{
		if (!*src)
		{
			dst[i++] = '\0';
			continue ;
		}
		dst[i++] = *src++;
	}
	return (dst);
}
