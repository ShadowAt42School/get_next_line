/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 02:05:17 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/03 19:18:49 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		dest_int;
	char	*ptr;

	dest_int = ft_strlen(dest);
	ptr = ft_memccpy((dest + dest_int), src, '\0', n);
	if (!ptr)
		dest[dest_int + n] = '\0';
	return (dest);
}
