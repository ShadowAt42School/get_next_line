/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 19:55:29 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/05 22:33:58 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	c_cpy;

	string = (unsigned char*)str;
	c_cpy = (unsigned char)c;
	while (n)
	{
		if (*string == c_cpy)
			break ;
		string++;
		n--;
	}
	return (n == 0 ? NULL : (void*)(string));
}
