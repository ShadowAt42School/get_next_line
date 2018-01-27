/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimdelim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 22:39:27 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/04 22:39:53 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimdelim(char const *s, char delim)
{
	char		*newstr;
	const char	*s_reverse;
	int			s_len;
	int			logic_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	s_reverse = s + s_len - 1;
	while (*s == delim)
		s++;
	if (!*s)
		return (ft_strdup(""));
	while (*s_reverse == delim)
		s_reverse--;
	if (s_reverse < s)
		return (NULL);
	s_reverse++;
	logic_len = s_reverse - s;
	newstr = ft_strnew(logic_len);
	if (!newstr)
		return (NULL);
	while (s_reverse != s)
		*newstr++ = *s++;
	return (newstr - logic_len);
}
