/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 19:34:43 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/04 20:37:51 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*newstr;
	const char	*s_reverse;
	int			s_len;
	int			logic_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	s_reverse = s + s_len - 1;
	while (SPACES2(*s))
		s++;
	if (!*s)
		return (ft_strdup(""));
	while (SPACES2(*s_reverse))
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
