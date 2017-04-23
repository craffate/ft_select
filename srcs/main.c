/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:23:01 by craffate          #+#    #+#             */
/*   Updated: 2017/04/23 15:14:00 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_term		g_term;

void		refresh_pos(t_select **select, const int ac)
{
	t_select		*tmp;
	t_select		*orig;
	unsigned int	i;
	unsigned int	j;
	size_t			si;

	tmp = *select;
	orig = *select;
	i = 0;
	j = 0;
	si = 0;
	if (ac > g_term.win.ws_row)
	{
		while (tmp->next)
		{
			si += ft_strlen(tmp->av) + 1;
			if (si > g_term.win.ws_col)
			{
				i = 0;
				si = 0;
				tmp->pos[0] = i++;
				tmp->pos[1] = ++j;
			}
			else
				tmp->pos[0] = i++;
			tmp->pos[1] = j;
			tmp = tmp->next;
		}
		if (si > g_term.win.ws_col)
		{
			i = 0;
			si = 0;
			tmp->pos[0] = i++;
			tmp->pos[1] = ++j;
		}
		else
			tmp->pos[0] = i++;
		tmp->pos[1] = j;
		tmp = tmp->next;
	}
	else
	{
		while (tmp->next)
		{
			tmp->pos[0] = 0;
			tmp->pos[1] = i++;
			tmp = tmp->next;
		}
		tmp->pos[0] = 0;
		tmp->pos[1] = i;
	}
}

static int	loop(t_select **select)
{
	t_select		*head;
	int				rd;
	char			buf[RDSIZE];

	refresh_pos(select, g_term.ac);
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
	g_term.ac = ac - 1;
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
