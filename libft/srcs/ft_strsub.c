/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:51:15 by craffate          #+#    #+#             */
/*   Updated: 2017/03/17 10:53:19 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int st, size_t si)
{
	char			*s2;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (!(s2 = (char *)malloc(sizeof(char) * si + 1)))
		return (NULL);
	i = 0;
	while (si)
	{
		s2[i++] = s[st++];
		si--;
	}
	s2[i] = 0;
	return (s2);
}
