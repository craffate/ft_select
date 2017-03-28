/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:12:36 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 14:16:31 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *data, size_t si)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (data)
	{
		if (!(node->data = (void *)malloc(sizeof(si))))
			return (NULL);
		ft_memcpy(node->data, data, si);
		node->si = si;
	}
	else
	{
		node->data = NULL;
		node->si = 0;
	}
	node->next = NULL;
	return (node);
}
