/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 08:32:37 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 08:41:41 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_factorial(const int n)
{
	long long int	i;

	if (n < 0 || n > 20)
		return (0);
	i = 1;
	if (n == 0)
		return (i);
	if (n > 0)
		i = n * ft_factorial(n - 1);
	return (i);
}
