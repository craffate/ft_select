/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:34:17 by craffate          #+#    #+#             */
/*   Updated: 2017/03/24 22:11:30 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strpush(char **s, const char c)
{
	char	*str;
	size_t	si;

	str =
	((si = ft_strlen(*s)) % MALLOCSIZE_STR) ? *s :
	(char *)malloc(sizeof(char) * (si + MALLOCSIZE_STR + 1));
	str[si] = c;
	str[si + 1] = 0;
	if (str == *s)
		return ;
	while (si--)
		str[si] = (*s)[si];
	free(*s);
	*s = str;
}
