/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 04:55:05 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 05:51:34 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	i;
	char			*s2;

	if (!s)
		return (NULL);
	if (!(s2 = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	i = -1u;
	while (s[++i])
		s2[i] = s[i];
	s2[i] = 0;
	return (s2);
}
