/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:23:01 by craffate          #+#    #+#             */
/*   Updated: 2017/04/13 05:34:33 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	loop(t_select **select, t_term *term)
{
	t_select		*head;
	int				rd;
	char			buf[RDSIZE];
	int				*konami;
	unsigned int	ki;

	print_args(select, term);
	head = *select;
	konami = init_konami();
	ki = 0;
	while ((rd = read(0, buf, RDSIZE)))
	{
		buf[rd] = 0;
		if (catch_char(&head, select, term, buf))
			return (0);
		if (rd == -1)
		{
			errors(E_RD);
			return (-1);
		}
		konami_scan(&ki, konami, buf);
		ioctl(0, TIOCGWINSZ, &term->win);
		print_args(select, term);
	}
	return (0);
}

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
	tcgetattr(0, &term.tmodes);
	tcgetattr(0, &term.tmodesdfl);
	ioctl(0, TIOCGWINSZ, &term.win);
	if (s_init(&select, (const char **)av))
		return (-1);
	if (term_init(&term))
		return (-1);
	if (loop(&select, &term))
		return (-1);
	if (reset(&term))
		return (-1);
	return (0);
}
