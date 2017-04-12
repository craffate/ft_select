/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 08:38:01 by craffate          #+#    #+#             */
/*   Updated: 2017/04/12 18:39:21 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	display(t_select *tmp)
{
	if (tmp->curr && !tmp->selected)
		ft_printf("{green}[{eoc}%s%s%s{green}]{eoc}", ULINE, tmp->av, RST);
	else if (tmp->selected && !tmp->curr)
		ft_printf("{green}[{eoc}%s%s%s{green}]{eoc}", INV, tmp->av, RST);
	else if (tmp->selected && tmp->curr)
		ft_printf("{green}[{eoc}%s%s%s%s{green}]{eoc}", INV, ULINE,
				tmp->av, RST);
	else
		ft_printf("{green}[{eoc}%s{green}]{eoc}", tmp->av);
}

void		print_args(t_select **select)
{
	t_select	*tmp;

	tmp = *select;
	ft_putstr(tgetstr(CLEAR, NULL));
	while (tmp->next)
	{
		display(tmp);
		tmp = tmp->next;
	}
	display(tmp);
}
