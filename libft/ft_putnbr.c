/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 23:04:56 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/05 00:26:38 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	interim;

	interim = 0;
	if (n == INT_MIN)
		write(1, INT_MIN_STR, 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = n * (-1);
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
		}
		interim = '0' + n % 10;
		write(1, &interim, 1);
	}
}
