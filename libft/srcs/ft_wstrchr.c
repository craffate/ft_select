/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:06:33 by craffate          #+#    #+#             */
/*   Updated: 2017/03/17 13:08:43 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcast-qual"

wchar_t	*ft_wstrchr(const wchar_t *s, const int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (wchar_t)c)
		s++;
	return (*s == (wchar_t)c ? (wchar_t *)s : NULL);
}

#pragma clang diagnostic pop
