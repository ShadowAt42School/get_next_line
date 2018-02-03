/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 20:18:02 by maghayev          #+#    #+#             */
/*   Updated: 2018/02/02 03:10:16 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

/*
** Type defs
*/
typedef	unsigned char	t_byte;
typedef unsigned int	t_bool;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
/*
** Pre-Def values
** Macroses Part 0
*/
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define INT_MIN_STR "-2147483648"
# define INT_MAX_STR "2147483647"
# define TRUE 1
# define FALSE 0

/*
** Casts
** Macroses Part 1
*/
# define LINTP(x) ((long int*)x)
# define INTP(x) ((int*)x)
# define SINTP(x) ((short int*)x)
# define CHRP(x) ((char*)x)

/*
** Sizes
** Macroses Part 2
*/
# define LIS sizeof(long int)
# define LS sizeof(long)
# define IS sizeof(int)
# define SIS sizeof(short int)
# define CS sizeof(char)
# define PS sizeof(char*)

/*
** Logic Based Actions
** Macroses
*/
# define ABS(x) (x < 0 ? -x : x)
# define SPACES(x) (x == '\v' || x == '\r' || x == '\f' || SPACES2(x))
# define SPACES2(x) (x == '\t' || x == ' ' || x == '\n')

/*
** C Type Checks
** Macroses
*/
# define IS_DIGIT(x) (x >= 48 && x <= 57 ? TRUE : FALSE)
# define IS_UPPER(x) (x >= 65 && x <= 90 ? TRUE : FALSE)
# define IS_LOWER(x) (x >= 97 && x <= 122 ? TRUE : FALSE)
# define IS_ALPHA(x) ((IS_UPPER(x) || IS_LOWER(x)) ? TRUE : FALSE)
# define IS_ALNUM(x) (IS_ALPHA(x) || IS_DIGIT(x) ? TRUE : FALSE)
# define IS_PRINT(x) (x >= 32 && x <= 126 ? TRUE : FALSE)
# define IS_NONPRINT(x) ((x >= 0 && x <= 31) || x == 127 ? TRUE : FALSE)

/*
**	Strings
*/
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
int				ft_strwordsdelim(const char *str, char delim);
int				ft_strlendelim(const char *str, char delim);
char			*ft_strdupdelim(const char *s1, char delim);
char			*ft_strtrimdelim(char const *s, char delim);

/*
** Convertions
*/
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);

/*
**	System Writes
*/
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putnbr(int n);
void			ft_print_byte(t_byte byte);
void			ft_object_bit_print(size_t const size, void const *const ptr);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
/*
**	Memmory
*/
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
void			*ft_memset(void *str, int c, size_t n);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memrealloc(
							void *content, size_t cur_size, size_t des_size);
void			*ft_memjoin(void *sh, const void *sn, size_t shl, size_t snh);
void			*ft_memdup(const void *cont, size_t size);
void			*ft_memshrink(void *area, void *start, size_t len);

/*
**	C Type Checks
*/
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isalnum(int c);

/*
** Lists
*/
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new_lst);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstpush(t_list **alst, t_list *new_lst);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstfrem(t_list **head);
t_list			*ft_lstlrem(t_list *head);
t_list			*ft_lstanydel(t_list *head, t_list *nd);

#endif
