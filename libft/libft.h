/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:53:58 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/27 14:06:28 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <xlocale.h>
# include <wchar.h>
# define TRUE 1
# define FALSE 0
# define DIGITS			"0123456789ABCDEF"
# define RESET			"\033[0m"
# define BLACK 			"\033[0;30m"
# define RED 			"\033[0;31m"
# define GREEN 			"\033[0;32m"
# define YELLOW 		"\033[0;33m"
# define BLUE 			"\033[0;34m"
# define PURPLE 		"\033[0;35m"
# define CYAN 			"\033[0;36m"
# define WHITE 			"\033[0;37m"
# define BOLDBLACK		"\033[1m\033[30m"
# define BOLDRED		"\033[1m\033[31m"
# define BOLDGREEN		"\033[1m\033[32m"
# define BOLDYELLOW		"\033[1m\033[33m"
# define BOLDBLUE		"\033[1m\033[34m"
# define BOLDMAGENTA	"\033[1m\033[35m"
# define BOLDCYAN		"\033[1m\033[36m"
# define BOLDWHITE		"\033[1m\033[37m"

/*
** Partie 1 & 2
*/

void			*ft_memalloc(size_t size);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t len);
void			ft_memdel(void **ap);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *str);
void			ft_putendl_fd(char const *str, int fd);
void			ft_putnbr(int nb);
void			ft_putnbr_fd(int n, int fd);
void			ft_putwstr(wchar_t *str);
void			ft_putstr_fd(char const *str, int fd);
void			ft_strclr(char *str);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putstr_color(char *str, char *color);
void			ft_swap_string(char *s1, char *s2);

unsigned int	ft_atoi_nbase(const char *str, int base, int len);
unsigned int	ft_atoi_base(const char *str, int base);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_atoi(const char *str);
long			ft_atoi_long(const char *str);
int				ft_putstr(const char *str);
int				ft_putchar(char c);
int				ft_isalnum(int c);
int				ft_isnum(char const *str);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isblank(int c);
int				ft_isdigit(int c);
int				ft_isgraph(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_ispunct(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_isxdigit(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_count_char(char *str, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				get_next_line(int const fd, char **line);
int				ft_binlen(unsigned int n);
int				ft_charwlen(int c);
int				ft_strwlen(int *str);
int				ft_putnwchar(int c, int size);
int				ft_putwchar(int c);
int				ft_putnwstr(int *str, int len);

char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_itoa_base_l(unsigned long int n, int base);
char			*ft_itoa_base_ll(unsigned long long int n, int base);
char			*ft_itoa_base_uint(uintmax_t n, int base);
char			*ft_itoa_base(unsigned int n, int base);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_ultimate(char *s1, char *s2, int option);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strlower(char *str);
char			*ft_strcapitalize(char *str);

size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dst, char *src, size_t n);
size_t			ft_count_words(const char *str, char c);
int				ft_printf(char const *format, ...);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** Partie Bonus
*/

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t const content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *n);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

#endif
