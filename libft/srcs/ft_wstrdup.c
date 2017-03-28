/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 09:29:22 by craffate          #+#    #+#             */
/*   Updated: 2017/03/16 09:31:11 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(const wchar_t *s)
{
	unsigned int	i;
	wchar_t			*s2;

	if (!(s2 = (wchar_t *)malloc(sizeof(wchar_t) * ft_wstrlen(s) + 1)))
		return (NULL);
	i = -1u;
	while (s[++i])
		s2[i] = s[i];
	s2[i] = 0;
	return (s2);
}
