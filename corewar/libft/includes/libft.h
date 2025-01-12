/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:43:36 by mlinhard          #+#    #+#             */
/*   Updated: 2016/09/26 21:31:08 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf.h"
# include "get_next_line.h"
# include <string.h>
# include <stdint.h>
# include <wchar.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putchar(char c);
int					ft_putstr(char const *s);
void				ft_putnbr(int n);
int					ft_putendl(char const *s);
void				ft_print_memory(const void *addr, size_t size);

size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);

char				*ft_itoa(int n);
char				*ft_itoastatic(intmax_t n);
int					ft_atoi(const char *nptr);
char				*ft_ldtoa(long double ld, int preci);
intmax_t			ft_atoimax(const char *str);
char				*ft_imaxtoa_base(intmax_t n, const char *b);
char				*ft_uimaxtoa_base(uintmax_t n, const char *b);
int					ft_pow(int x, unsigned int y);

char				*ft_pcol(char *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strtoupper(char *str);
char				*ft_strtolower(char *str);
char				*ft_strrev(char *str);
int					ft_countwords(const char *s, char c);
char				*ft_wchartostr(wchar_t const wc);
char				*ft_wstrtostr(wchar_t const *src);
char				*ft_strrealloc(char *str, int size);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);

int					ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
int					ft_memdel(void **ap);
char				*ft_stralloc(const char *s);

char				*ft_strnew(size_t size);
int					ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

typedef struct		s_ldtoa
{
	long double		save;
	long double		ld;
	long double		tmp;
	char			*ret;
	int				divi;
	int				multi;
	int				preci;
	int				isneg;
	int				i;
}					t_ldtoa;

#endif
