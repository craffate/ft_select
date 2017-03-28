/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:04:12 by craffate          #+#    #+#             */
/*   Updated: 2017/03/17 13:05:25 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrnew(const size_t si)
{
	wchar_t			*s;
	unsigned int	i;

	if (!(s = (wchar_t *)malloc(sizeof(wchar_t) * (si + 1))))
		return (NULL);
	i = -1u;
	s[si] = 0;
	while (++i < si)
		s[i] = 0;
	return (s);
}
