/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:23:01 by craffate          #+#    #+#             */
/*   Updated: 2017/03/29 07:22:42 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			main(int ac, char **av)
{
	t_select	*select;
	t_term		term;

	if (ac < 2)
	{
		errors(E_NOARGS);
		return (-1);
	}
	select = NULL;
	tcgetattr(0, &term.tmodesdfl);
	sig(SIG_IGN);
	if (s_init(&select, (const char **)av))
		return (-1);
	if (term_init(&term))
		return (-1);
	if (term_setmodes_dfl(&term))
		return (-1);
	sig(SIG_DFL);
	return (0);
}
