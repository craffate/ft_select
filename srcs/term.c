/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 05:29:02 by craffate          #+#    #+#             */
/*   Updated: 2017/03/29 07:24:55 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
	char	*term_env;

	term_env = getenv("TERM");
	if (tgetent(NULL, term_env) == ERR)
	{
		errors(E_TERMENV);
		return (-1);
	}
	term->tmodes.c_lflag &= (unsigned long)~(ICANON);
	term->tmodes.c_lflag &= (unsigned long)~(ECHO | ECHOE | ECHOK | ECHONL);
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
	return (0);
}
