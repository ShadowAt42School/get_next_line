/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 19:11:23 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/04 19:31:27 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = ft_strnew(s1_len + s2_len + 1);
	if (!newstr)
		return (NULL);
	newstr = ft_memccpy(newstr, s1, '\0', s1_len + 1) - 1;
	ft_memccpy(newstr, s2, '\0', s2_len);
	return (newstr - s1_len);
}
