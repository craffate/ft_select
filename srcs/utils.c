/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:39:18 by craffate          #+#    #+#             */
/*   Updated: 2017/04/24 08:50:04 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

size_t			get_longest_arg(t_select **select)
{
	size_t		si;
	t_select	*tmp;

	si = 0;
	tmp = *select;
	while (tmp->next)
	{
		si = ft_strlen(tmp->av) > si ? ft_strlen(tmp->av) : si;
		tmp = tmp->next;
	}
	si = ft_strlen(tmp->av) > si ? ft_strlen(tmp->av) : si;
	return (si);
}

static t_select	*get_next_node(t_select **head, t_select **select)
{
	t_select	*tmp;

	if (!((*head)->next))
		tmp = (*head)->prev;
	if (!((*head)->prev))
	{
		goto_next(select);
		tmp = (*head)->next;
	}
	if ((*head)->next && ((*head)->prev))
		tmp = (*head)->next;
	if (!((*head)->next) && !(((*head)->prev)))
		return (NULL);
	tmp->curr = 1;
	return (tmp);
}

size_t			scan_win(t_select **select)
{
	size_t		si;
	t_select	*tmp;

	si = 0;
	tmp = *select;
	while (tmp->next)
	{
		si += ft_strlen(tmp->av) + tmp->offset;
		tmp = tmp->next;
	}
	si += ft_strlen(tmp->av) + tmp->offset;
	return (si);
}

static int		catch_char2(t_select **head, const char buf[RDSIZE])
{
	if (buf[0] == 32)
	{
		(*head)->selected = (*head)->selected == 1 ? 0 : 1;
		goto_next(head);
	}
	else if (buf[0] == 4)
	{
		ft_putendl("\n\x1b[7mGood bye!\x1b[0m");
		return (1);
	}
	else if (buf[0] == 27 && buf[1] == 0)
	{
		reset();
		exit(EXIT_SUCCESS);
	}
	else if (buf[0] == 27 && (buf[2] == 65 || buf[2] == 66
			|| buf[2] == 67 || buf[2] == 68))
		update_head(head, buf);
	return (0);
}

int				catch_char(t_select **head, t_select **select,
				const char buf[RDSIZE])
{
	t_select	*tmp;

	if (buf[0] == '\n')
	{
		print_args_ret(select);
		return (1);
	}
	else if (buf[0] == 127 || buf[0] == 126)
	{
		if (!(tmp = get_next_node(head, select)))
		{
			ft_putstr_fd(tgetstr(CLEAR, NULL), g_term.tty);
			ft_putendl_fd(LISTEMPTIED, 2);
			return (1);
		}
		s_delnode(head);
		refresh_pos(select);
		*head = tmp;
	}
	else if (catch_char2(head, buf))
		return (1);
	return (0);
}
