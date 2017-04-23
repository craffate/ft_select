/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:22:01 by craffate          #+#    #+#             */
/*   Updated: 2017/04/23 16:18:41 by craffate         ###   ########.fr       */
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
# include <fcntl.h>
# include <signal.h>

# define RDSIZE 3

# define RST			"\x1b[0m"
# define BOLD			"\x1b[1m"
# define ULINE			"\x1b[4m"
# define INV			"\x1b[7m"

# define CLEAR			"cl"
# define LSTART			"cr"
# define CM				"cm"
# define HIDECUR		"vi"
# define RESCUR			"ve"

# define S_MALLOC		"Memory allocation failed"
# define S_NOARGS		"usage: ft_select [arguments ...]"
# define S_SINIT		"Error while initializing structure"
# define S_TMODES		"Error while setting terminal attributes"
# define S_TMODESDFL	"Error while setting terminal attributes back to default"
# define S_TERMENV		"Error while getting TERM environment variable"
# define S_RD			"Error while reading on standard input"

# define LISTEMPTIED	"List has been emptied, exiting..."
# define WINSIZE		"Window's size is too small"

typedef struct			s_select
{
	char				*av;
	int					selected;
	int					curr;
	int					pos[2];
	struct s_select		*prev;
	struct s_select		*next;
}						t_select;

typedef struct			s_term
{
	struct winsize		win;
	struct termios		tmodesdfl;
	struct termios		tmodes;
	int					tty;
	int					ac;
	t_select			**select;
}						t_term;

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

extern t_term	g_term;

int			catch_char(t_select **head,	t_select **select, const char buf[RDSIZE]);
int			reset(void);
int			s_init(t_select **select, const char **av);
int			term_init(void);
int			term_setmodes(void);
int			term_setmodes_dfl(void);
size_t		get_longest_arg(t_select **select);
size_t		scan_win(t_select **select);
t_select	*s_newnode(const char *av);
void		errors(const int ec);
void		goto_end(t_select **head);
void		goto_next(t_select **head);
void		goto_prev(t_select **head);
void		goto_start(t_select **head);
void		goto_xy(t_select **head, const int x, const int y);
void		print_args(t_select **select);
void		print_args_ret(t_select **select);
void		refresh_pos(t_select **select, const int ac);
void		s_addnode(t_select **select, t_select *node);
void		s_delnode(t_select **node);
void		s_display(t_select *select);
void		s_freenode(t_select **node);
void		sig(void);
void		update_head(t_select **head, const char buf[RDSIZE]);

#endif
