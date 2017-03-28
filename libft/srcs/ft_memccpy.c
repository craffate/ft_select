/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 10:08:01 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 10:13:50 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, const int c, size_t si)
{
	unsigned int	i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)dst;
	while (si--)
		if ((*s++ = ((const unsigned char *)src)[i++]) == (unsigned char)c)
			return (s);
	return (NULL);
}
