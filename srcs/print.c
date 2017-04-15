/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 08:38:01 by craffate          #+#    #+#             */
/*   Updated: 2017/04/15 11:39:57 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	display(t_select *tmp, t_term *term)
{
	if (tmp->curr && !tmp->selected)
	{
		ft_putstr_fd(ULINE, term->tty);
		ft_putstr_fd(tmp->av, term->tty);
		ft_putstr_fd(RST, term->tty);
	}
	else if (tmp->selected && !tmp->curr)
	{
		ft_putstr_fd(INV, term->tty);
		ft_putstr_fd(tmp->av, term->tty);
		ft_putstr_fd(RST, term->tty);
	}
	else if (tmp->selected && tmp->curr)
	{
		ft_putstr_fd(INV, term->tty);
		ft_putstr_fd(ULINE, term->tty);
		ft_putstr_fd(tmp->av, term->tty);
		ft_putstr_fd(RST, term->tty);
	}
	else
		ft_putstr_fd(tmp->av, term->tty);
}

static int	print_separator(t_term *term, size_t *si)
{
	if (*si > term->win.ws_col)
	{
		ft_putchar_fd(('\n'), term->tty);
		*si = 0;
	}
	else
		ft_putchar_fd(' ', term->tty);
	return (0);
}

void		print_args(t_select **select, t_term *term)
{
	size_t		si;
	t_select	*tmp;

	if (scan_sizes(select, term))
	{
		ft_putendl_fd(WINSIZE, term->tty);
		return ;
	}
	tmp = *select;
	ft_putstr_fd(tgetstr(CLEAR, NULL), term->tty);
	si = 0;
	while (tmp->next)
	{
		si += si == 0 ? ft_strlen(tmp->av) + ft_strlen(tmp->next->av) :
		ft_strlen(tmp->next->av);
		display(tmp, term);
		print_separator(term, &si);
		tmp = tmp->next;
	}
	display(tmp, term);
}

static int	next_sel(t_select *tmp)
{
	if (tmp->selected)
		return (1);
	while (tmp->next)
	{
		if (tmp->selected)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		print_args_ret(t_select **select, t_term *term)
{
	t_select	*tmp;

	tmp = *select;
	ft_putstr_fd(tgetstr(CLEAR, NULL), term->tty);
	while (tmp->next)
	{
		if (tmp->selected)
		{
			ft_putstr(tmp->av);
			if (next_sel(tmp->next))
				ft_putchar(' ');
		}
		tmp = tmp->next;
	}
	if (tmp->selected)
		ft_putstr(tmp->av);
}
