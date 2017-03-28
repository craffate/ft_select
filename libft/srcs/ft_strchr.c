/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 06:07:43 by craffate          #+#    #+#             */
/*   Updated: 2017/03/17 13:09:19 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcast-qual"

char	*ft_strchr(const char *s, const int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (wchar_t)c)
		s++;
	return (*s == (char)c ? (char *)s : NULL);
}

#pragma clang diagnostic pop
