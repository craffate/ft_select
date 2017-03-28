/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 09:28:10 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 09:29:15 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(const size_t si)
{
	void	*ptr;

	if (!(ptr = (void *)malloc(si)))
		return (NULL);
	ft_memset(ptr, 0, si);
	return (ptr);
}
