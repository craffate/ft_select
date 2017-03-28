/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 10:17:03 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 10:32:16 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t si)
{
	const unsigned char	*s3;
	const unsigned char	*s4;

	s3 = (const unsigned char *)s1;
	s4 = (const unsigned char *)s2;
	while (si--)
	{
		if (*s3 != *s4)
			return (*s3 - *s4);
		s3++;
		s4++;
	}
	return (0);
}
