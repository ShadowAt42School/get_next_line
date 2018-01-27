/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_byte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 00:50:50 by maghayev          #+#    #+#             */
/*   Updated: 2017/12/03 00:54:43 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_byte(t_byte byte)
{
	int		asci;

	asci = 128;
	while (asci)
	{
		if (byte & asci)
			ft_putnbr(1);
		else
			ft_putnbr(0);
		asci >>= 1;
	}
}
