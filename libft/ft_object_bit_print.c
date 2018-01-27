/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object_bit_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:24:11 by maghayev          #+#    #+#             */
/*   Updated: 2017/12/03 19:18:27 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_object_bit_print(size_t const size, void const *const ptr)
{
	unsigned char	*b;
	unsigned char	byte;
	int				i;
	int				j;

	b = (unsigned char*)ptr;
	i = size;
	while (--i >= 0)
	{
		j = 8;
		while (--j >= 0)
		{
			byte = (b[i] >> j) & 1;
			ft_putnbr(byte);
		}
		ft_putchar(' ');
	}
	ft_putchar('\n');
}
