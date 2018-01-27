/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:01:45 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/05 16:11:10 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_strsplit_eng(char const *trimed, int words, char delim)
{
	char	**str_r;
	int		count;

	count = words;
	str_r = (char**)ft_memalloc(sizeof(char*) * (words + 1));
	if (!str_r)
		return (NULL);
	while (*trimed)
	{
		if (*trimed == delim && *(trimed + 1) == delim)
			trimed++;
		else
		{
			if (*trimed == delim)
				trimed++;
			*str_r++ = (words == 1 ?
				ft_strdup(trimed) : ft_strdupdelim(trimed, delim));
			trimed += (words == 1 ?
				(int)ft_strlen(trimed) : (int)ft_strlendelim(trimed, delim));
			words--;
		}
	}
	return (str_r - count);
}

char			**ft_strsplit(char const *s, char c)
{
	int			words;
	char		*s_trimed;

	words = 0;
	if (!s)
		return ((char**)ft_memalloc(sizeof(char*)));
	s_trimed = ft_strtrimdelim(s, c);
	if (!s_trimed)
		return (NULL);
	if (!*s_trimed)
		return (ft_strsplit_eng(s_trimed, 0, c));
	words = ft_strwordsdelim(s_trimed, c);
	return (ft_strsplit_eng(s_trimed, words, c));
}
