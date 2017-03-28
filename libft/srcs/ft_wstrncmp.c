/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 09:49:00 by craffate          #+#    #+#             */
/*   Updated: 2017/03/16 09:50:54 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrncmp(const wchar_t *s1, const wchar_t *s2, size_t n)
{
	while (*s1 && *s1 == *s2 && n)
	{
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (*(const wchar_t *)--s1 - *(const wchar_t *)--s2);
	return (*(const wchar_t *)s1 - *(const wchar_t *)s2);
}
