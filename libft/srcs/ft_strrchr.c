/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 07:23:12 by craffate          #+#    #+#             */
/*   Updated: 2017/03/16 09:34:44 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcast-qual"

char	*ft_strrchr(const char *s, const int c)
{
	size_t	si;

	if (!s)
		return (NULL);
	si = ft_strlen(s) + 1;
	while (si--)
		if (s[si] == (char)c)
			return (&(((char *)s)[si]));
	return (NULL);
}

#pragma clang diagnostic pop
