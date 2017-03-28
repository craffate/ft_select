/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:45:27 by craffate          #+#    #+#             */
/*   Updated: 2017/03/17 10:48:28 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcast-qual"

char	*ft_strnstr(const char *s1, const char *s2, size_t si)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	size_t			l;

	i = 0;
	if (!s2)
		return ((char *)s1);
	l = ft_strlen(s2);
	while (s1[i] && si >= l)
	{
		j = 0;
		k = i;
		while (s1[j] == s2[j])
		{
			j++;
			k++;
			if (!s2[j])
				return (&((char *)s1)[i]);
		}
		i++;
		si--;
	}
	return (NULL);
}

#pragma clang diagnostic pop
