/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:23:01 by craffate          #+#    #+#             */
/*   Updated: 2017/04/24 08:26:18 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_term		g_term;

void		refresh_pos(t_select **select)
{
	size_t			msi;
	size_t			lsi;
	int				x;
	int				y;
	t_select		*tmp;

	msi = get_longest_arg(select);
	lsi = 0;
	x = 0;
	y = 0;
	tmp = *select;
	while (tmp->next)
	{
		if (lsi + (msi - ft_strlen(tmp->av)) + ft_strlen(tmp->av)
			>= g_term.win.ws_col)
		{
			x = 0;
			lsi = 0;
			++y;
		}
		tmp->pos[0] = x++;
		tmp->pos[1] = y;
		tmp->offset = msi - ft_strlen(tmp->av);
		lsi += ft_strlen(tmp->av) + tmp->offset;
		tmp = tmp->next;
	}
	tmp->pos[0] = x;
	tmp->pos[1] = y;
	tmp->offset = msi - ft_strlen(tmp->av);
}

static int	loop(t_select **select)
{
	t_select		*head;
	int				rd;
	char			buf[RDSIZE];

	refresh_pos(select);
	print_args(select);
	head = *select;
	while ((rd = read(0, buf, RDSIZE)))
	{
		buf[rd] = 0;
		if (catch_char(&head, select, buf))
			return (0);
		if (rd == -1)
			continue ;
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
