/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 10:24:50 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 10:31:37 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t si)
{
	unsigned int	i;
	const char		*src2;

	i = 0;
	src2 = (const char *)src;
	if (dst > src)
		while (si--)
			((char *)dst)[si] = ((const char *)src)[si];
	else
		while (si--)
			((char *)dst)[i++] = *src2++;
	return (dst);
}
