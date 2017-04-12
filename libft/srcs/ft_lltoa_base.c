/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 09:15:59 by craffate          #+#    #+#             */
/*   Updated: 2017/03/25 00:56:18 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	getsize(long long int *n, const int b)
{
	unsigned int	si;
	long long int	n2;

	si = 1;
	if (*n < 0)
	{
		si++;
		*n *= -1;
	}
	n2 = *n;
	while (n2 /= b)
		si++;
	return (si);
}

char				*ft_lltoa_base(long long int n, const int b)
{
	unsigned int	si;
	char			*s;
	short			sign;

	sign = n < 0 ? -1 : 0;
	si = getsize(&n, b);
	if (!(s = (char *)malloc(sizeof(char) * (si + 1))))
		return (NULL);
	s[si] = 0;
	while (si--)
	{
		s[si] = ("0123456789abcdef")[n % b];
		n /= b;
	}
	if (sign)
		*s = 45;
	return (s);
}
