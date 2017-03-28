/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 09:58:32 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 10:09:53 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t si)
{
	unsigned int	i;
	char			*s;

	i = 0;
	s = (char *)dst;
	while (si--)
		*s++ = ((const char *)src)[i++];
	return (dst);
}
