/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:25:08 by craffate          #+#    #+#             */
/*   Updated: 2017/04/17 13:01:28 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	send_sigtstp(void)
{
	char			sig[2];

	ft_putstr_fd(tgetstr(RESCUR, NULL), g_term.tty);
	tcsetattr(0, TCSANOW, &g_term.tmodesdfl);
	sig[0] = (char)g_term.tmodesdfl.c_cc[VSUSP];
	sig[1] = 0;
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, sig);
}

static void	sig_handler(int action)
{
	if (action == SIGTSTP)
		send_sigtstp();
	else if (action == SIGCONT)
	{
		signal(SIGTSTP, sig_handler);
		term_init();
		print_args(g_term.select);
	}
	else if (action == SIGWINCH)
		print_args(g_term.select);
	else
	{
		tcsetattr(0, TCSANOW, &g_term.tmodesdfl);
		exit(EXIT_SUCCESS);
	}
}

void		sig(void)
{
	unsigned int		i;

	i = -1u;
	while (++i < 32)
		signal(i, sig_handler);
}
