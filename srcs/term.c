/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 05:29:02 by craffate          #+#    #+#             */
/*   Updated: 2017/04/17 13:49:11 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		reset(void)
{
	if (term_setmodes_dfl())
		return (-1);
	sig();
	ft_putstr_fd(tgetstr(RESCUR, NULL), g_term.tty);
	return (0);
}

int		term_setmodes_dfl(void)
{
	if (tcsetattr(0, TCSANOW, &g_term.tmodesdfl))
	{
		errors(E_TMODESDFL);
		return (-1);
	}
	return (0);
}

int		term_setmodes(void)
{
	if (tgetent(NULL, getenv("TERM")) == ERR)
	{
		errors(E_TERMENV);
		return (-1);
	}
	g_term.tmodes.c_lflag &= (unsigned long)~(ECHO | ECHOE | ECHOK | ECHONL
	| ICANON);
	g_term.tmodes.c_cc[VMIN] = 1;
	g_term.tmodes.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &g_term.tmodes))
	{
		errors(E_TMODES);
		return (-1);
	}
	return (0);
}

int		term_init(void)
{
	sig();
	g_term.tty = open("/dev/tty", O_WRONLY);
	if (term_setmodes())
		return (-1);
	ft_putstr_fd(tgetstr(HIDECUR, NULL), g_term.tty);
	return (0);
}
