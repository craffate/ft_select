/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 11:12:38 by craffate          #+#    #+#             */
/*   Updated: 2017/04/23 15:09:46 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	goto_start(t_select **head)
{
	(*head)->curr = 0;
	while ((*head)->prev)
		*head = (*head)->prev;
	(*head)->curr = 1;
}

void	goto_end(t_select **head)
{
	(*head)->curr = 0;
	while ((*head)->next)
		*head = (*head)->next;
	(*head)->curr = 1;
}

void	goto_next(t_select **head)
{
	if (!((*head)->next))
	{
		goto_start(head);
		return ;
	}
	(*head)->curr = 0;
	*head = (*head)->next;
	(*head)->curr = 1;
}

void	goto_prev(t_select **head)
{
	if (!((*head)->prev))
	{
		goto_end(head);
		return ;
	}
	(*head)->curr = 0;
	*head = (*head)->prev;
	(*head)->curr = 1;
}

void	update_head(t_select **head, const char buf[RDSIZE])
{
	if (buf[2] == 65)
		goto_xy(head, (*head)->pos[0], (*head)->pos[1] - 1);
	else if (buf[2] == 66)
		goto_xy(head, (*head)->pos[0], (*head)->pos[1] + 1);
	else if (buf[2] == 67)
		goto_next(head);
	else if (buf[2] == 68)
		goto_prev(head);
}
