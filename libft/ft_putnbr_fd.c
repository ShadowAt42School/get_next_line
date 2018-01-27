/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 00:26:09 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/05 00:27:10 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	interim;

	interim = 0;
	if (n == INT_MIN)
		write(fd, INT_MIN_STR, 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = n * (-1);
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		interim = '0' + n % 10;
		write(fd, &interim, 1);
	}
}
