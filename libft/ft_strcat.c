/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 01:30:26 by maghayev          #+#    #+#             */
/*   Updated: 2017/12/06 00:19:16 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		src_len;
	int		dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	dest += dest_len;
	src_len = ft_strlen(src);
	while (i < (src_len + 1))
	{
		dest[i] = src[i];
		i++;
	}
	return (dest - dest_len);
}
