/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <msakovyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:52:45 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/03/30 18:21:56 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>

# define BLUE  "\033[0;34m"
# define RED "\033[1;31m"
# define GREEN "\033[0;32m"
# define LGREEN "\033[0;32m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define LCYAN "\033[1;36m"
# define YELLOW "\033[1;33m"
# define LBLUE "\033[1;34m"
# define PINK "\033[1;35m"
# define WHITE "\033[1;37m"
# define NC "\033[0m"

# define STR (f.modifier == 'x') ? "0x" : "0X"
# define UPPER (f.modifier == 'X') ? 1 : 0

# define BUFF_SIZE 1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl
{
	char			*str;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

typedef struct		s_frmt
{
	int				max;
	int				min;
	char			modifier;
	char			spec;
	int				minus;
	int				plus;
	int				sharp;
	int				space;
	int				zero;
	int				prec;
	int				bytes;
	int				i;
}					t_frmt;

int					ft_count_word(char *s);
int					get_next_line(const int fd, char **line);
int					ft_atoi(const char *str);
intmax_t			ft_atointmxt(const char *str);
int					ft_atoi_ptr(const char *str, int *i);
void				ft_bzero(void *s, size_t n);
int					ft_isprint(int c);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *d, const void *s, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *str);
int					ft_strlen(const char *s);
char				*ft_strncat(char *s1, char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *h, char *n, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, char *needle);
void				ft_strdel(char **as);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char const *s2);
char				*ft_strnjoin(char const *s1, char const *s2, int n);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
int					ft_putchar(char c);
int					ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putlnbr(long int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_nextprime(int n);
int					ft_isprime(int n);
void				ft_swap(int *a, int *b);
int					*ft_range(int min, int max);
char				*ft_strrev(char *s);
int					ft_putnstr(char const *s, int n);
void				ft_splitdel(char **split);
int					ft_printf(char *str, ...);
void				start_check(char *str, va_list ap, t_frmt *frmt);
void				check(char *str, va_list ap, t_frmt *frmt);
void				finish_check(char *str, t_frmt *f);

int					print(char *str, va_list ap, t_frmt *frmt);
int					print2(char *str, va_list ap, t_frmt *frmt);
int					print3(char *str, va_list ap, t_frmt *frmt);
int					print4(char *str, va_list ap, t_frmt *frmt);

int					repeat_char(char c, int n);
int					count_base(intmax_t n, int base);
int					count_ubase(uintmax_t n, int base);
int					print_base(intmax_t n, int base, int bytes, int upper);
int					print_ubase(uintmax_t n, int base, int bytes, int upper);

int					putstr_u(wchar_t *s);
int					putnstr_u(wchar_t *s, int n);
int					print_u_s(t_frmt frmt, va_list ap);
int					print_s(t_frmt frmt, va_list ap);
int					counter_c(wchar_t c);

int					count_unicode(wchar_t *s, int n);
int					print_unicode(wchar_t value);

int					print_unicode_c(va_list ap);
int					print_c(t_frmt frmt, intmax_t c);
int					print_d(t_frmt frmt, intmax_t d);
int					print_d2(t_frmt frmt, intmax_t d, int bytes, int minus);
int					print_d3(t_frmt frmt, intmax_t d, int bytes, int minus);

int					print_p(t_frmt frmt, va_list ap);
int					print_p2(t_frmt frmt, unsigned long int	u, int ox);
int					print_uox(t_frmt frmt, uintmax_t u);
int					print_uox2(t_frmt frmt, uintmax_t u, int ox, int base);
int					print_uox3(t_frmt frmt, uintmax_t u, int ox, int base);

#endif
