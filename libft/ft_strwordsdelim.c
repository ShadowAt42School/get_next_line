/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwordsdelim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:33:05 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/05 15:01:42 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strwordsdelim(const char *str, char delim)
{
	int		words;

	words = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == delim && *(str + 1) != delim)
			words += (str++ ? 1 : 1);
		else
			str++;
	}
	if (*str == '\0' && *(str - 1) != delim && ft_isascii(*(str - 1)))
		words++;
	return (words);
}
