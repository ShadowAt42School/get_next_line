/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 20:17:14 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/02 20:08:16 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		mover;
	void	*tmp;

	tmp = s;
	while (n)
	{
		if (n >= 8)
			*(long int *)tmp &= (mover = sizeof(long int)) ? 0x00 : 0x00;
		else if (n >= 4)
			*(int *)tmp &= (mover = sizeof(int)) ? 0x00 : 0x00;
		else
			*(char *)tmp &= (mover = sizeof(char)) ? 0x00 : 0x00;
		tmp += mover;
		n -= mover;
	}
}
