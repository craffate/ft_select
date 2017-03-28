/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:15:05 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 15:18:02 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(const int n, const int fd)
{
	int		n2;

	n2 = n;
	if (n2 < 0)
	{
		ft_putchar(45);
		n2 *= -1;
	}
	if (n2 >= 10)
		ft_putnbr(n2 / 10);
	ft_putchar_fd(n2 % 10 + 48, fd);
}
