/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 01:04:40 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/03 19:30:37 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*result;
	char	*result_tmp;

	result = NULL;
	while (*str != '\0')
	{
		result_tmp = ft_strchr(str, c);
		if (!result_tmp)
			break ;
		else
			result = result_tmp;
		if (*result == '\0')
			break ;
		str = result_tmp + 1;
	}
	return (result);
}
