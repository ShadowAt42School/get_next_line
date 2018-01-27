/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 00:32:31 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/05 23:12:48 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_memcpy_eng(void *str1, const void *str2, size_t n)
{
	int		mover;
	void	*str1_tmp;

	mover = 0;
	str1_tmp = str1;
	while (n > 0 && (n -= mover) && (str1_tmp += mover) && (str2 += mover))
	{
		mover = 0;
		if (n >= 8)
		{
			*(long int*)str1_tmp = *(long int*)str2;
			mover = sizeof(long int);
		}
		else if (n >= 4)
		{
			*(int*)str1_tmp = *(int*)str2;
			mover = sizeof(int);
		}
		else
		{
			*(char*)str1_tmp = *(char*)str2;
			mover = sizeof(char);
		}
	}
	return (str1);
}

void			*ft_memcpy(void *str1, const void *str2, size_t n)
{
	if (!str1 && !str2 && n == 0)
		return (ft_memcpy_eng(str1, str2, n));
	if (!str1)
		*(long int*)str1 = *(long int*)str1;
	if (!str2)
		*(long int*)str2 = *(long int*)str2;
	return (ft_memcpy_eng(str1, str2, n));
}
