/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:39:18 by craffate          #+#    #+#             */
/*   Updated: 2017/03/31 12:09:34 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			catch_char(t_select **head, const char buf[RDSIZE])
{
	if (buf[0] == '\n')
	{
		(*head)->selected = (*head)->selected == 1 ? 0 : 1;
		goto_next(head);
	}
	else if (buf[0] == 4)
	{
		ft_putendl("\n\x1b[7mGood bye!\x1b[0m");
		return (2);
	}
	else if (buf[2] == 65 || buf[2] == 66 || buf[2] == 67 || buf[2] == 68)
		update_head(head, buf);
	return (0);
}
