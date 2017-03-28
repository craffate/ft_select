/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 08:00:37 by craffate          #+#    #+#             */
/*   Updated: 2017/03/16 09:35:03 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, const size_t si)
{
	unsigned int	i;
	unsigned int	j;
	size_t			k;

	i = 0;
	j = 0;
	k = ft_strlen(src);
	while (dst[i] && i < si)
		i++;
	if (si > 0)
		while (src[j] && i < si - 1)
			dst[i++] = src[j++];
	if (j > 0)
	{
		dst[i] = 0;
		return (k + i - j);
	}
	return (k + i);
}
