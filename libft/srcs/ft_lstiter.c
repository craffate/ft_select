/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:08:10 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 14:10:21 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstiter(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst2;

	lst2 = NULL;
	if (lst)
	{
		lst2 = (*f)(lst);
		lst2->next = ft_lstmap(lst->next, (*f));
		return (lst2);
	}
	return (NULL);
}
