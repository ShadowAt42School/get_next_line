/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupdelim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:59:03 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/04 23:28:43 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupdelim(const char *s1, char delim)
{
	char	*str1;
	int		len;

	len = ft_strlendelim(s1, delim);
	str1 = ft_strnew(len);
	if (str1 == NULL)
		return (NULL);
	ft_memcpy(str1, s1, len);
	return ((char*)str1);
}
