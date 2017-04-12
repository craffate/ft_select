/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 05:29:02 by craffate          #+#    #+#             */
/*   Updated: 2017/04/12 19:37:06 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		reset(t_term *term)
{
	if (term_setmodes_dfl(term))
		return (-1);
	sig(SIG_DFL);
	ft_putstr(tgetstr(RESCUR, NULL));
	return (0);
}

int		term_setmodes_dfl(t_term *term)
{
	if (tcsetattr(0, TCSANOW, &term->tmodesdfl))
	{
		errors(E_TMODESDFL);
		return (-1);
	}
	return (0);
}

int		term_setmodes(t_term *term)
{
	if (tgetent(NULL, getenv("TERM")) == ERR)
	{
		errors(E_TERMENV);
		return (-1);
	}
	term->tmodes.c_lflag &= (unsigned long)~(ECHO | ECHOE | ECHOK | ECHONL
	| ICANON);
	term->tmodes.c_cc[VMIN] = 1;
	term->tmodes.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term->tmodes))
	{
		errors(E_TMODES);
		return (-1);
	}
	return (0);
}

int		term_init(t_term *term)
{
	if (term_setmodes(term))
		return (-1);
	ft_putstr(tgetstr(HIDECUR, NULL));
	return (0);
}
