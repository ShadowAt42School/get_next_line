/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:35:27 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/04 16:36:00 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		len;
	int		index;

	index = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (*s)
		*str++ = f(index++, *s++);
	*str = '\0';
	return (str - len);
}
