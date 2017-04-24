/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 08:38:01 by craffate          #+#    #+#             */
/*   Updated: 2017/04/24 08:50:05 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	print_offset(t_select *tmp)
{
	unsigned int	i;

	i = tmp->offset + 1;
	while (--i)
		ft_putchar_fd(' ', g_term.tty);
}

static void	display(t_select *tmp)
{
	if (tmp->curr && !tmp->selected)
	{
		ft_putstr_fd(ULINE, g_term.tty);
		ft_putstr_fd(tmp->av, g_term.tty);
		ft_putstr_fd(RST, g_term.tty);
	}
	else if (tmp->selected && !tmp->curr)
	{
		ft_putstr_fd(INV, g_term.tty);
		ft_putstr_fd(tmp->av, g_term.tty);
		ft_putstr_fd(RST, g_term.tty);
	}
	else if (tmp->selected && tmp->curr)
	{
		ft_putstr_fd(INV, g_term.tty);
		ft_putstr_fd(ULINE, g_term.tty);
		ft_putstr_fd(tmp->av, g_term.tty);
		ft_putstr_fd(RST, g_term.tty);
	}
	else
		ft_putstr_fd(tmp->av, g_term.tty);
	if (tmp->next && tmp->next->pos[1] == tmp->pos[1])
		print_offset(tmp);
}

void		print_args(t_select **select)
{
	t_select	*tmp;

	tmp = *select;
	refresh_pos(select);
	ft_putstr_fd(tgetstr(CLEAR, NULL), g_term.tty);
	if (g_term.win.ws_row * g_term.win.ws_col < scan_win(select))
	{
		ft_putendl_fd(WINSIZE, g_term.tty);
		return ;
	}
	while (tmp->next)
	{
		display(tmp);
		if (tmp->next)
		{
			tmp->pos[1] == tmp->next->pos[1] ? ft_putchar_fd(' ', g_term.tty) :
			ft_putchar_fd('\n', g_term.tty);
		}
		else
			ft_putchar_fd(' ', g_term.tty);
		tmp = tmp->next;
	}
	display(tmp);
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
	return (tmp->selected ? 1 : 0);
}

void		print_args_ret(t_select **select)
{
	t_select	*tmp;

	tmp = *select;
	ft_putstr_fd(tgetstr(CLEAR, NULL), g_term.tty);
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
