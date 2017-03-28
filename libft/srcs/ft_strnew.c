/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 05:52:15 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 05:57:50 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(const size_t si)
{
	char			*s;
	unsigned int	i;

	if (!(s = (char *)malloc(sizeof(char) * (si + 1))))
		return (NULL);
	i = -1u;
	s[si] = 0;
	while (++i < si)
		s[i] = 0;
	return (s);
}
