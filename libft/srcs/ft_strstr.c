/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:41:43 by craffate          #+#    #+#             */
/*   Updated: 2017/03/17 10:47:58 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcast-qual"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	if (!s2)
		return ((char *)s1);
	while (s1[i])
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
	}
	return (NULL);
}

#pragma clang diagnostic pop
