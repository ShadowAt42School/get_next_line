/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 00:20:38 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/02 20:10:32 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *str, int c, size_t n)
{
	unsigned long int		lic;
	int						mover;
	void					*str_tmp;

	mover = 0;
	lic = 0;
	str_tmp = str;
	c = (unsigned char)c;
	lic = (unsigned int)(((((lic << 8) | c) << 16) |
		(((unsigned int)c << 8) | c)) << 8 | c);
	lic = ((unsigned long int)lic << 32) | (unsigned long int)lic;
	ft_bzero(str, n);
	while (n > 0 && (str_tmp += mover) && (n -= mover) && !(mover = 0))
	{
		if (n >= 8 && (mover = sizeof(long int)))
			*(unsigned long int*)str_tmp |= lic;
		else if (n >= 4 && (mover = sizeof(int)))
			*(unsigned int*)str_tmp |= (unsigned int)lic;
		else if ((mover = sizeof(char)))
			*(unsigned char*)str_tmp |= (unsigned char)lic;
	}
	return (str);
}
