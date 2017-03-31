/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 08:38:01 by craffate          #+#    #+#             */
/*   Updated: 2017/03/31 10:27:31 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		print_args(t_select **select)
{
	t_select	*tmp;

	tmp = *select;
	ft_putstr(tgetstr(CLEAR, NULL));
	while (tmp->next)
	{
		if (tmp->curr && !tmp->selected)
			ft_printf("{green}[{eoc}%s%s%s{green}]{eoc}", ULINE, tmp->av, RST);
		else if (tmp->selected && !tmp->curr)
			ft_printf("{green}[{eoc}%s%s%s{green}]{eoc}", INV, tmp->av, RST);
		else if (tmp->selected && tmp->curr)
			ft_printf("{green}[{eoc}%s%s%s%s{green}]{eoc}", INV, ULINE, tmp->av, RST);
		else
			ft_printf("{green}[{eoc}%s{green}]{eoc}", tmp->av);
		tmp = tmp->next;
	}
	if (tmp->curr && !tmp->selected)
		ft_printf("{green}[{eoc}%s%s%s{green}]{eoc}", ULINE, tmp->av, RST);
	else if (tmp->selected && !tmp->curr)
		ft_printf("{green}[{eoc}%s%s%s{green}]{eoc}", INV, tmp->av, RST);
	else if (tmp->selected && tmp->curr)
		ft_printf("{green}[{eoc}%s%s%s%s{green}]{eoc}", INV, ULINE, tmp->av, RST);
	else
		ft_printf("{green}[{eoc}%s{green}]{eoc}", tmp->av);
}
