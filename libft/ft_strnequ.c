/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:56:49 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/04 16:59:34 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 && !s2)
		return (TRUE);
	if (!s1 || !s2)
		return (FALSE);
	if (ft_strncmp(s1, s2, n) != 0)
		return (FALSE);
	return (TRUE);
}
