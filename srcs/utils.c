/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:39:18 by craffate          #+#    #+#             */
/*   Updated: 2017/04/12 19:32:35 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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

int				catch_char(t_select **head, t_select **select,
				const char buf[RDSIZE])
{
	t_select	*tmp;

	if (buf[0] == 127)
	{
		if (!(tmp = get_next_node(head, select)))
		{
			ft_putstr(tgetstr(CLEAR, NULL));
			ft_putendl_fd(LISTEMPTIED, 2);
			return (1);
		}
		s_delnode(head);
		*head = tmp;
	}
	else if (buf[0] == '\n')
	{
		(*head)->selected = (*head)->selected == 1 ? 0 : 1;
		goto_next(head);
	}
	else if (buf[0] == 4)
	{
		ft_putendl("\n\x1b[7mGood bye!\x1b[0m");
		return (1);
	}
	else if (buf[2] == 65 || buf[2] == 66 || buf[2] == 67 || buf[2] == 68)
		update_head(head, buf);
	return (0);
}
