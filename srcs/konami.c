/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   konami.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:09:20 by craffate          #+#    #+#             */
/*   Updated: 2017/04/01 11:22:50 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			*init_konami(void)
{
	int				*konami;

	if (!(konami = (int *)malloc(sizeof(int) * 10)))
	{
		errors(E_MALLOC);
		return (NULL);
	}
	konami[0] = 65;
	konami[1] = 65;
	konami[2] = 66;
	konami[3] = 66;
	konami[4] = 68;
	konami[5] = 67;
	konami[6] = 68;
	konami[7] = 67;
	konami[8] = 98;
	konami[9] = 97;
	return (konami);
}

void		konami_scan(unsigned int *ki, const int *konami, const char *buf)
{
	if (*ki < 8)
		buf[2] == konami[*ki] ? ++*ki : (*ki = 0);
	else
		buf[0] == konami[*ki] ? ++*ki : (*ki = 0);
	if (*ki == 10)
		konami_code();
}

void		konami_code(void)
{
	ft_putstr(tgetstr(CLEAR, NULL));
	print_konami();
	sleep(5);
}

void		print_konami(void)
{
	ft_putstr("\x1b[31m\x1b[1m\x1b[5m");
	ft_putstr(" /$$   /$$                                             /$$\n");
	ft_putstr("| $$  /$$/                                            |__/\n");
	ft_putstr("| $$ /$$/   /$$$$$$  /$$$$$$$   /$$$$$$  /$$$$$$/$$$$  /$$\n");
	ft_putstr("| $$$$$/   /$$__  $$| $$__  $$ |____  $$| $$_  $$_  $$| $$\n");
	ft_putstr("| $$  $$  | $$  \\ $$| $$  \\ $$  /$$$$$$$| $$ \\ $$ \\");
	ft_putstr(" $$| $$\n");
	ft_putstr("| $$\\  $$ | $$  | $$| $$  | $$ /$$__  $$| $$ | $$ | $$| $$\n");
	ft_putstr("| $$ \\  $$|  $$$$$$/| $$  | $$|  $$$$$$$| $$ | $$ | $$| $$\n");
	ft_putstr("|__/  \\__/ \\______/ |__/  |__/ \\_______/|__/ |__/ |__/");
	ft_putstr("|__/\n");
	ft_putstr("\x1b[0m");
}
