/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:01:17 by craffate          #+#    #+#             */
/*   Updated: 2017/03/17 14:41:58 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_savele(unsigned int i, const char *s)
{
	if (*s == 'h')
	{
		if (*s + 1 == 'h')
			i = HH;
		else
			i = H;
	}
	if (*s == 'l')
	{
		if (*s + 1 == 'l')
			i = LL;
		else
			i = L;
	}
	i = *s == 'j' ? J : i;
	i = *s == 'z' ? Z : i;
	return (i);
}

unsigned int	ft_savefl(unsigned int i, const char c)
{
	i = c == '#' ? SHARP : i;
	i = c == '0' ? ZERO : i;
	i = c == '-' ? MINUS : i;
	i = c == '+' ? PLUS : i;
	i = c == ' ' ? SPACE : i;
	return (i);
}
