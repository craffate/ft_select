/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 04:36:29 by craffate          #+#    #+#             */
/*   Updated: 2017/03/25 05:04:09 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <wchar.h>

# define MALLOCSIZE_STR 32

typedef struct		s_list
{
	void			*data;
	size_t			si;
	struct s_list	*next;
}					t_list;

typedef struct		s_stack
{
	int				*data;
	unsigned int	head;
	char			padding[4];
	size_t			si;
}					t_stack;

char				**ft_strsplit(const char *s, const char c);
char				*ft_lltoa(long long int n);
char				*ft_lltoa_base(long long int n, const int b);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, const int c);
char				*ft_strcpy(char *src, const char *dst);
char				*ft_strdup(const char *s);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t l);
char				*ft_strnew(const size_t si);
char				*ft_strnstr(const char *s1, const char *s2, size_t si);
char				*ft_strrchr(const char *s, const int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(const char *s, unsigned int st, size_t si);
char				*ft_strtrim(const char *s);
int					ft_absval(const int n);
int					ft_atoi(const char *s);
int					ft_isalnum(const int c);
int					ft_isalpha(const int c);
int					ft_isascii(const int c);
int					ft_isdigit(const int n);
int					ft_isprint(const int c);
int					ft_isspace(const int c);
int					ft_memcmp(const void *s1, const void *s2, size_t si);
int					ft_stackisempty(const t_stack stack);
int					ft_stackisfull(const t_stack stack);
int					ft_stackpeek(const t_stack stack);
int					ft_stackpop(t_stack *stack);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_tolower(const int c);
int					ft_toupper(const int c);
int					ft_ugetchar(void);
int					ft_wstrcmp(const wchar_t *s1, const wchar_t *s2);
int					ft_wstrncmp(const wchar_t *s1, const wchar_t *s2, size_t n);
long long int		ft_atoll(const char *s);
long long int		ft_factorial(const int n);
size_t				ft_strlcat(char *dst, const char *src, const size_t si);
size_t				ft_strlen(const char *s);
size_t				ft_wcharlen(const wchar_t c);
size_t				ft_wstrlen(const wchar_t *s);
t_list				*ft_lstiter(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(const void *data, size_t si);
t_stack				ft_stacknew(size_t si);
void				*ft_memalloc(const size_t si);
void				*ft_memccpy(void *dst, const void *src, const int c,
					size_t si);
void				*ft_memchr(const void *s, const int c, size_t si);
void				*ft_memcpy(void *dst, const void *src, size_t si);
void				*ft_memmove(void *dst, const void *src, size_t si);
void				*ft_memset(void *b, const int c, size_t si);
void				ft_bzero(char *s, size_t si);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_memdel(void **ap);
void				ft_putchar(const int c);
void				ft_putchar_fd(const int c, const int fd);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, const int fd);
void				ft_putnbr(const int n);
void				ft_putnbr_fd(const int n, const int fd);
void				ft_putstr(const char *s);
void				ft_putstr_fd(const char *s, const int fd);
void				ft_putwchar(const wchar_t c);
void				ft_putwstr(const wchar_t *s);
void				ft_stackmove(t_stack *a, t_stack *b);
void				ft_stackprint(t_stack stack);
void				ft_stackpush(t_stack *stack, int data);
void				ft_stackrotate(t_stack *stack);
void				ft_stackrrotate(t_stack *stack);
void				ft_stackswap(t_stack *stack);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strpush(char **s, const char c);
wchar_t				*ft_wstrcat(wchar_t *s1, const wchar_t *s2);
wchar_t				*ft_wstrchr(const wchar_t *s, const int c);
wchar_t				*ft_wstrdup(const wchar_t *s);
wchar_t				*ft_wstrjoin(const wchar_t *s1, const wchar_t *s2);
wchar_t				*ft_wstrnew(const size_t si);

#endif
