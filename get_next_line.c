/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 20:33:02 by maghayev          #+#    #+#             */
/*   Updated: 2018/02/02 08:05:35 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_bool		clean_up(t_linemeta *lnmeta)
{
	if (lnmeta->str_rem)
	{
		ft_strdel(&lnmeta->str_rem);
		lnmeta->str_rem = NULL;
	}
	ft_memdel((void**)&lnmeta);
	return (TRUE);
}

t_bool		read_file(t_linemeta *lnmeta)
{
	t_buffread	lnread;

	ft_bzero(&lnread, sizeof(t_buffread));
	if ((lnmeta->bread = read(lnmeta->file_d, lnread.read_l, BUFF_SIZE)) <= 0)
	{
		if (lnmeta->bread == 0)
			return (DONE);
		clean_up(lnmeta);
		return (FALSE);
	}
	lnread.nl = (char*)ft_memchr(lnread.read_l, '\n', lnmeta->bread);
	if (!lnmeta->str_rem)
		lnmeta->str_rem = (char*)ft_memdup(lnread.read_l, lnmeta->bread);
	else
		lnmeta->str_rem = (char*)ft_memjoin(
				lnmeta->str_rem, lnread.read_l, lnmeta->rem_wid, lnmeta->bread);
	if (lnread.nl)
		lnmeta->nl = lnmeta->str_rem + lnmeta->rem_wid +
			(lnread.nl - lnread.read_l);
	else
		lnmeta->nl = NULL;
	lnmeta->rem_wid += lnmeta->bread;
	return (TRUE);
}

t_bool		check_line(t_linemeta *lnmeta, char **line)
{
	t_bool	status;
	int		cpylen;

	while (!lnmeta->nl && !(lnmeta->nl = ft_memchr(
	lnmeta->str_rem, '\n', lnmeta->rem_wid)))
	{
		status = read_file(lnmeta);
		if (!status)
			return (FALSE);
		if (status == DONE)
			break ;
	}
	cpylen = (lnmeta->nl ? lnmeta->nl - lnmeta->str_rem : lnmeta->rem_wid);
	if (cpylen == 0 && lnmeta->rem_wid == 0)
	{
		clean_up(lnmeta);
		return (DONE);
	}
	*line = ft_memcpy(ft_strnew(cpylen), lnmeta->str_rem, cpylen);
	lnmeta->rem_wid -= cpylen + (lnmeta->nl ? 1 : 0);
	lnmeta->str_rem = ft_memshrink(lnmeta->str_rem,
			lnmeta->str_rem + cpylen + (lnmeta->nl ? 1 : 0), lnmeta->rem_wid);
	lnmeta->nl = NULL;
	return (TRUE);
}

t_bool		create_node(int fd, t_list **lnlist)
{
	t_linemeta		*lnmeta;
	t_bool			readstatus;
	t_list			*newlist;

	lnmeta = (t_linemeta*)ft_memalloc(sizeof(t_linemeta));
	lnmeta->file_d = fd;
	readstatus = read_file(lnmeta);
	if (readstatus == FALSE || readstatus == DONE)
	{
		if (readstatus == DONE)
			return (DONE);
		return (FALSE);
	}
	newlist = ft_lstnew(lnmeta, sizeof(t_linemeta));
	ft_lstadd(lnlist, newlist);
	ft_memdel((void**)&lnmeta);
	return (INIT);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*lnlist;
	t_list			*lnlistcpy;
	int				checkstatus;

	if (fd < 0 || !line)
		return (-1);
	lnlistcpy = lnlist;
	while (lnlistcpy && ((t_linemeta*)lnlistcpy->content)->file_d != fd)
		lnlistcpy = lnlistcpy->next;
	if (lnlistcpy)
	{
		checkstatus = check_line((t_linemeta*)lnlistcpy->content, line);
		if (checkstatus == DONE || checkstatus == FALSE)
			lnlist = ft_lstanydel(lnlist, lnlistcpy);
	}
	else
		checkstatus = create_node(fd, &lnlist);
	if (checkstatus == FALSE)
		return (-1);
	if (checkstatus == DONE)
		return (0);
	if (checkstatus == TRUE)
		return (1);
	return (get_next_line(fd, line));
}
