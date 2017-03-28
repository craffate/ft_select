/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 09:37:14 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 09:45:25 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcast-qual"

void	*ft_memchr(const void *s, const int c, size_t si)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (si--)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	return (0);
}

#pragma clang diagnostic pop
