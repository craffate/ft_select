/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 09:29:42 by craffate          #+#    #+#             */
/*   Updated: 2017/03/17 11:02:17 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, const int c, size_t si)
{
	unsigned int	i;

	i = -1u;
	while (si--)
		(((char *)b)[++i] = (char)c);
	return (b);
}
