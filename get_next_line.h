/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 04:23:10 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/27 04:13:17 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <fcntl.h>

# define BUFF_SIZE 1000

typedef struct	s_linemeta
{
	int		file_d;
	char	*str_rem;
	char	*nmp;
	int		rem_wid;
	int		npos;
}				t_linemeta;

typedef struct	s_buffread
{
	int		byread;
	char	*read_l;
	char	*nline;
}				t_buffread;

typedef struct	s_linec
{
	char		*pline;
	int			npos;
	t_bool		iread;
}				t_linec;

int				get_next_line(const int fd, char **line);
t_bool			clean_up(t_linemeta *lnmeta);
t_bool			read_file(t_linemeta *lnmeta);
int				create_node(int fd, char **line, t_list **lnlist);
int				check_line(t_linemeta *lnmeta, char **line);
#endif
