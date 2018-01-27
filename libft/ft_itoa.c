/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 23:40:22 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/05 00:16:40 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		digit_counter(int n)
{
	int		count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		d_count;

	if (n == INT_MIN)
		return (ft_strdup(INT_MIN_STR));
	if (!n)
		return (ft_strdup("0"));
	d_count = digit_counter(n);
	str = ft_strnew(d_count);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		n *= -1;
	}
	str += d_count - 1;
	while (n)
	{
		*str-- = (n % 10) + '0';
		n /= 10;
	}
	return (*str != '-' ? ++str : str);
}
