/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 01:20:16 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/04 23:25:31 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str1;
	int		len;

	len = ft_strlen(s1);
	str1 = ft_strnew(len);
	if (str1 == NULL)
		return (NULL);
	ft_memcpy(str1, s1, len);
	return ((char*)str1);
}
