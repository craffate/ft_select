/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:25:08 by craffate          #+#    #+#             */
/*   Updated: 2017/04/13 06:02:19 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	send_sigtstp(t_term *term)
{
	char			sig[2];

	reset(term);
	sig[0] = (char)term->tmodes.c_cc[VSUSP];
	sig[1] = 0;
	ioctl(0, TIOCSTI, sig);
}

void		sig(void (*f)(int action))
{
	int	i;

	i = -1;
	while (++i < 32)
		signal(i, f);
}
