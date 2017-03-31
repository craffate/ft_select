/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:22:01 by craffate          #+#    #+#             */
/*   Updated: 2017/03/31 12:08:44 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include "ft_printf.h"
# include <curses.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>

# define RDSIZE 8

# define RST			"\x1b[0m"
# define BOLD			"\x1b[1m"
# define ULINE			"\x1b[4m"
# define INV			"\x1b[7m"

# define CLEAR			"cl"
# define LSTART			"cr"
# define CM				"cm"

# define S_MALLOC		"Memory allocation failed\n"
# define S_NOARGS		"usage: ft_select [arguments ...]\n"
# define S_SINIT		"Error while initializing structure\n"
# define S_TMODES		"Error while setting terminal attributes\n"
# define S_TMODESDFL	"Error while setting terminal attributes back to default\n"
# define S_TERMENV		"Error while getting TERM environment variable\n"
# define S_RD			"Error while reading on standard input\n"

typedef struct			s_term
{
	struct winsize		win;
	struct termios		tmodesdfl;
	struct termios		tmodes;
}						t_term;

typedef struct			s_select
{
	char				*av;
	int					selected;
	int					curr;
	struct s_select		*prev;
	struct s_select		*next;
}						t_select;

typedef enum			e_errors
{
	E_FAILURE = -1,
	E_SUCCESS,
	E_MALLOC,
	E_NOARGS,
	E_SINIT,
	E_TMODES,
	E_TMODESDFL,
	E_TERMENV,
	E_RD
}						t_errors;

void		konami_code(void);
void		print_konami(void);
void		update_head(t_select **head, const char buf[RDSIZE]);
void		print_args(t_select **select);
void		sig(void (*f)(int action));
void		s_display(t_select *select);
void		s_freenode(t_select **node);
void		s_addnode(t_select **select, t_select *node);
int			reset(t_term *term);
int			term_setmodes(t_term *term);
int			term_setmodes_dfl(t_term *term);
int			term_init(t_term *term);
int			s_init(t_select **select, const char **av);
int			catch_char(t_select **head, const char buf[RDSIZE]);
t_select	*s_newnode(const char *av);
void		errors(const int ec);
void		goto_next(t_select **head);
void		goto_prev(t_select **head);
int			*init_konami(void);

#endif
