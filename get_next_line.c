/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 04:22:57 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/27 07:09:03 by maghayev         ###   ########.fr       */
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

int			check_line(t_linemeta *lnmeta, char **line)
{
	t_linec		linc;

	ft_bzero(&linc, sizeof(t_linec));
	linc.pline = ft_memchr(lnmeta->str_rem, '\n', lnmeta->rem_wid);
	if (!linc.pline && (linc.iread = read_file(lnmeta)) == TRUE)
		return (check_line(lnmeta, line));
	if (!linc.pline && (linc.iread == FALSE || (linc.iread == DONE &&
													lnmeta->rem_wid == 0)))
	{
		clean_up(lnmeta);
		if (linc.iread == DONE && lnmeta->rem_wid == 0)
			return (0);
		return (-1);
	}
	linc.npos = (linc.pline ? linc.pline - lnmeta->str_rem : lnmeta->rem_wid);
	free(*line);
	*line = ft_memcpy(ft_strnew(linc.npos), lnmeta->str_rem, linc.npos);
	linc.pline = (linc.pline ?
	ft_strsub(lnmeta->str_rem, linc.npos + 1, lnmeta->rem_wid - (linc.npos + 1))
		: NULL);
	lnmeta->rem_wid -= (linc.pline ? linc.npos + 1 : lnmeta->rem_wid);
	(linc.pline ? ft_strdel(&lnmeta->str_rem) : 0);
	lnmeta->str_rem = linc.pline ? linc.pline : lnmeta->str_rem;
	(!linc.pline ? ft_strdel(&lnmeta->str_rem) : 0);
	return (1);
}

t_bool		read_file(t_linemeta *lnmeta)
{
	t_buffread	lnread;

	ft_bzero(&lnread, sizeof(t_buffread));
	lnread.read_l = ft_memalloc(BUFF_SIZE);
	if ((lnread.byread = read(lnmeta->file_d, lnread.read_l, BUFF_SIZE)) <= 0)
	{
		ft_strdel(&lnread.read_l);
		if (lnread.byread == 0)
			return (DONE);
		clean_up(lnmeta);
		return (FALSE);
	}
	if (!lnmeta->str_rem)
		lnmeta->str_rem = (char*)ft_memdup(lnread.read_l, lnread.byread);
	else
		lnmeta->str_rem = (char*)ft_memjoin(
				lnmeta->str_rem, lnread.read_l, lnmeta->rem_wid, lnread.byread);
	lnmeta->rem_wid += lnread.byread;
	ft_strdel(&lnread.read_l);
	return (TRUE);
}

int			create_node(int fd, char **line, t_list **lnlist)
{
	t_linemeta		*lnmeta;
	t_bool			readstatus;
	t_list			*newlist;

	lnmeta = (t_linemeta*)ft_memalloc(sizeof(t_linemeta));
	lnmeta->file_d = fd;
	readstatus = read_file(lnmeta);
	if (readstatus == FALSE)
		return (FALSE);
	if (readstatus == DONE)
	{
		check_line(lnmeta, line);
		*line = NULL;
		return (DONE);
	}
	*line = ft_memalloc(0);
	newlist = ft_lstnew(lnmeta, sizeof(t_linemeta));
	ft_lstadd(lnlist, newlist);
	ft_memdel((void**)&lnmeta);
	return (TRUE);
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
		if (checkstatus <= 0)
			lnlist = ft_lstanydel(lnlist, lnlistcpy->content);
		return (checkstatus);
	}
	checkstatus = create_node(fd, line, &lnlist);
	if (checkstatus == FALSE)
		return (-1);
	if (checkstatus == DONE)
		return (0);
	return (get_next_line(fd, line));
}
