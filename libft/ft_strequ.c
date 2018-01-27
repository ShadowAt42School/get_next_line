/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:53:16 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/04 16:55:01 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (TRUE);
	if (!s1 || !s2)
		return (FALSE);
	if (ft_strcmp(s1, s2) != 0)
		return (FALSE);
	return (TRUE);
}
