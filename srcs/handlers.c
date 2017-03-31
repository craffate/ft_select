/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 05:43:34 by craffate          #+#    #+#             */
/*   Updated: 2017/03/29 08:49:51 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		errors(const int ec)
{
	if (ec == E_MALLOC)
		write(2, S_MALLOC, ft_strlen(S_MALLOC));
	else if (ec == E_NOARGS)
		write(2, S_NOARGS, ft_strlen(S_NOARGS));
	else if (ec == E_SINIT)
		write(2, S_SINIT, ft_strlen(S_SINIT));
	else if (ec == E_TMODES)
		write(2, S_TMODES, ft_strlen(S_TMODES));
	else if (ec == E_TMODESDFL)
		write(2, S_TMODESDFL, ft_strlen(S_TMODESDFL));
	else if (ec == E_TERMENV)
		write(2, S_TERMENV, ft_strlen(S_TERMENV));
	else if (ec == E_RD)
		write(2, S_RD, ft_strlen(S_RD));
	ft_printf("Error code: %i\n", ec);
}
