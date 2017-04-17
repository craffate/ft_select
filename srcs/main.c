/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:23:01 by craffate          #+#    #+#             */
/*   Updated: 2017/04/17 12:55:23 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_term		g_term;

static int	loop(t_select **select)
{
	t_select		*head;
	int				rd;
	char			buf[RDSIZE];
	int				*konami;
	unsigned int	ki;

	print_args(select);
	head = *select;
	konami = init_konami();
	ki = 0;
	while ((rd = read(0, buf, RDSIZE)))
	{
		buf[rd] = 0;
		if (catch_char(&head, select, buf))
			return (0);
		if (rd == -1)
			continue ;
		konami_scan(&ki, konami, buf);
		ioctl(0, TIOCGWINSZ, &g_term.win);
		print_args(select);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_select	*select;

	if (ac < 2)
	{
		errors(E_NOARGS);
		return (-1);
	}
	select = NULL;
	g_term.select = &select;
	tcgetattr(0, &g_term.tmodes);
	tcgetattr(0, &g_term.tmodesdfl);
	ioctl(0, TIOCGWINSZ, &g_term.win);
	if (s_init(&select, (const char **)av))
		return (-1);
	if (term_init())
		return (-1);
	if (loop(&select))
		return (-1);
	if (reset())
		return (-1);
	return (0);
}
