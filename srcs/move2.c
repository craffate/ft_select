/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 02:19:34 by craffate          #+#    #+#             */
/*   Updated: 2017/04/23 15:14:59 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	scout_y(t_select **head)
{
	int			ret;
	t_select	*tmp;

	ret = 0;
	tmp = *head;
	while (tmp->next)
	{
		ret = tmp->pos[1];
		tmp = tmp->next;
	}
	ret = tmp->pos[1];
	return (ret);
}

void		goto_xy(t_select **head, const int x, const int y)
{
	goto_start(head);
	if (y == -1)
	{
		goto_end(head);
		while ((*head)->prev)
		{
			if ((*head)->pos[0] == x)
				return ;
			goto_prev(head);
		}
	}
	else if (y == scout_y(head) + 1)
	{
		goto_start(head);
		while ((*head)->next)
		{
			if ((*head)->pos[0] == x)
				return ;
			goto_next(head);
		}
	}
	while ((*head)->next)
	{
		if ((*head)->pos[0] == x && (*head)->pos[1] == y)
			return ;
		goto_next(head);
	}
}
