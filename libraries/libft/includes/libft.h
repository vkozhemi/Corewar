/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 08:57:15 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/29 14:32:41 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

# define UI unsigned int
# define ULI unsigned long int
# define ULLI unsigned long long int
# define USI unsigned short int
# define UC unsigned char
# define BUFF_SIZE 128
# define ABS(Val) (Val < 0) ? -Val : Val

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl
{
	char			*buff;
	int				f_desu;
	struct s_gnl		*next;
}					t_gnl;

typedef struct		s_flag
{
	char			specs;
	int				minus;
	int				sharp;
	int				zero;
	int				width;
	int				prec;
	int				i;
	va_list			ap;
}					t_flag;

int					ft_abs(int val);
void				ft_error(char *str);
void				***ft_box_destructor(void ***box);
void				**ft_card_destructor(void **card);
int					get_next_line(const int fd, char **line);
int					ft_factorial(int nb);
size_t				ft_count_c(char const *str, char c);
void				ft_swap(int *i1, int *i2);
void				ft_swap_char(char *c1, char *c2);
const char			*ft_skip_char(char const *str, char c);
size_t				ft_word_count(char const *str, char c);
size_t				ft_intlen(int nb);
void				*ft_memset(void *mem, int val, size_t len);
void				ft_bzero(void *box, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t len);
void				*ft_memccpy(void *dest, const void *src, int c, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(void const *meme, int val, size_t len);
int					ft_memcmp(const void *meme1, const void *meme2, size_t len);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t len);
size_t				ft_strlcat(char *dest, const char *src, size_t len);
char				*ft_strchr(char *str, int symbol);
char				*ft_strrchr(char *str, int symbol);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strnstr(const char *str1, const char *str2, size_t len);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t len);
int					ft_atoi(const char *str);
int					ft_isalpha(int chr);
int					ft_isdigit(int chr);
int					ft_isalnum(int chr);
int					ft_isascii(int chr);
int					ft_isprint(int chr);
void				ft_toupper(char *chr);
int					ft_tolower(int chr);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
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
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_printf(const char *format, ...);
char				*pf_putx(UI n, int base, char *str, int sharp);
char				*pf_putlx(ULI n, int base, char *str, int sharp);
char				*pf_putllx(ULLI n, int base, char *str, int sharp);
char				*pf_putupx(UI n, int base, char *str, int sharp);
char				*pf_putuplx(ULI n, int base, char *str, int sharp);
char				*pf_putupllx(ULLI n, int base, char *str, int sharp);
char				*pf_putu(ULLI n, char *str);
int					pf_putc(char c);
char				*pf_putnbr(int n, char *str, t_flag *f);
char				*pf_putlnbr(long int n, char *str, t_flag *f);
char				*pf_putllnbr(long long int n, char *str, t_flag *f);
char				*pf_putaddr(unsigned long int p, char *str);
int					pf_puts(char const *s);
int					pf_uniparser(UI v, unsigned char *o);
void				pf_unic(UI v, t_flag *flag);
void				pf_unis(unsigned int *str, t_flag *flag);
void				pf_string(char *str, t_flag *flag);
void				pf_number(char *str, t_flag *flag);
void				pf_octal(char *str, t_flag *flag);
void				pf_hex(char *str, t_flag *flag);
void				pf_unsigned(char *str, t_flag *flag);
void				pf_char(char c, t_flag *flag);
void				pf_conver(const char **format, t_flag *flag);
void				pf_converh(const char **format, t_flag *f, char *buff);

#endif
