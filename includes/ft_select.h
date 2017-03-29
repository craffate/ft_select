/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:22:01 by craffate          #+#    #+#             */
/*   Updated: 2017/03/29 07:22:16 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include "ft_printf.h"
# include <curses.h>
# include <termios.h>
# include <term.h>

# define S_MALLOC		"Memory allocation failed\n"
# define S_NOARGS		"usage: ft_select [arguments ...]\n"
# define S_SINIT		"Error while initializing structure\n"
# define S_TMODES		"Error while setting terminal attributes\n"
# define S_TMODESDFL	"Error while setting terminal attributes back to default\n"
# define S_TERMENV		"Error while getting TERM environment variable\n"

typedef struct			s_term
{
	struct termios		tmodesdfl;
	struct termios		tmodes;
}						t_term;

typedef struct			s_select
{
	char				*av;
	int					selected;
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
	E_TERMENV
}						t_errors;

void		sig(void (*f)(int action));
void		s_display(t_select *select);
void		s_freenode(t_select **node);
void		s_addnode(t_select **select, t_select *node);
int			term_setmodes(t_term *term);
int			term_setmodes_dfl(t_term *term);
int			term_init(t_term *term);
int			s_init(t_select **select, const char **av);
t_select	*s_newnode(const char *av);
void		errors(const int ec);

#endif
