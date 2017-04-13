/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 08:38:01 by craffate          #+#    #+#             */
/*   Updated: 2017/04/13 21:51:21 by craffate         ###   ########.fr       */
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

void		print_args(t_select **select, t_term *term)
{
	t_select	*tmp;

	tmp = *select;
	ft_putstr_fd(tgetstr(CLEAR, NULL), term->tty);
	while (tmp->next)
	{
		display(tmp, term);
		ft_putchar_fd(' ', term->tty);
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
