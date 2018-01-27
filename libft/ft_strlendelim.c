/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlendelim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:54:50 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/04 23:30:50 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlendelim(const char *str, char delim)
{
	int		len;

	len = 0;
	if (!str)
		return (0);
	while (*str != delim)
	{
		len++;
		str++;
	}
	return (len);
}
