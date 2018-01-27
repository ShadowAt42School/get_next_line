/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:12:54 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/04 16:34:31 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (*s)
		*str++ = f(*s++);
	*str = '\0';
	return (str - len);
}
