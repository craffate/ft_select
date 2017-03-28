/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:06:54 by craffate          #+#    #+#             */
/*   Updated: 2017/03/17 12:08:44 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t l)
{
	char	*s;

	s = dst;
	while (l > 0 && *src)
	{
		*s++ = *src++;
		l--;
	}
	while (l > 0)
	{
		*s++ = 0;
		l--;
	}
	return (dst);
}
