/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 05:43:34 by craffate          #+#    #+#             */
/*   Updated: 2017/04/12 19:11:37 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		errors(const int ec)
{
	if (ec == E_MALLOC)
		ft_putendl_fd(S_MALLOC, 2);
	else if (ec == E_NOARGS)
		ft_putendl_fd(S_NOARGS, 2);
	else if (ec == E_SINIT)
		ft_putendl_fd(S_NOARGS, 2);
	else if (ec == E_TMODES)
		ft_putendl_fd(S_TMODES, 2);
	else if (ec == E_TMODESDFL)
		ft_putendl_fd(S_TMODESDFL, 2);
	else if (ec == E_TERMENV)
		ft_putendl_fd(S_TERMENV, 2);
	else if (ec == E_RD)
		ft_putendl_fd(S_RD, 2);
	ft_printf("Error code: %i\n", ec);
}
