/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 01:14:10 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/03 19:39:16 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char	*begin;
	const char	*pattern;

	if (*big == *little && *big == '\0')
		return ((char *)big);
	while (*big)
	{
		begin = big;
		pattern = little;
		while (*pattern && *big && *pattern == *big)
		{
			pattern++;
			big++;
		}
		if (!*pattern)
			return ((char *)begin);
		big = begin + 1;
	}
	return (NULL);
}
