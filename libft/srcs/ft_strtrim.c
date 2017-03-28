/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:58:34 by craffate          #+#    #+#             */
/*   Updated: 2017/03/17 12:04:13 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	blankcheck(const int c)
{
	return (c == ' ' || c == '\t' || c == '\n' ? 1 : 0);
}

char		*ft_strtrim(const char *s)
{
	unsigned int	i;
	unsigned long	j;
	size_t			k;
	char			*s2;

	if (!s)
		return (NULL);
	i = 0;
	k = ft_strlen(s);
	while (blankcheck(s[k - 1]))
		k--;
	while (blankcheck(s[i]))
		i++;
	if (!s[i])
	{
		s2 = ft_strnew(0);
		return (s2);
	}
	j = k - i;
	s2 = ft_strsub(s, i, j);
	return (s2);
}
