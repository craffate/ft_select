/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 01:05:48 by craffate          #+#    #+#             */
/*   Updated: 2017/04/24 07:19:16 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		s_delnode(t_select **node)
{
	if (!((*node)->prev))
		(*node)->next->prev = NULL;
	if (!((*node)->next))
		(*node)->prev->next = NULL;
	if ((*node)->prev && ((*node)->next))
	{
		(*node)->next->prev = (*node)->prev;
		(*node)->prev->next = (*node)->next;
	}
	s_freenode(node);
}

void		s_freenode(t_select **node)
{
	free((*node)->av);
	(*node)->av = NULL;
	free(*node);
	*node = NULL;
}

void		s_addnode(t_select **select, t_select *node)
{
	t_select	*tmp;

	if (!(*select))
	{
		node->curr = 1;
		*select = node;
		return ;
	}
	tmp = *select;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
}

t_select	*s_newnode(const char *av)
{
	t_select		*ret;

	if (!(ret = (t_select *)malloc(sizeof(t_select))))
	{
		errors(E_MALLOC);
		return (NULL);
	}
	if (!(ret->av = (char *)malloc(sizeof(char) * (ft_strlen(av) + 1))))
	{
		errors(E_MALLOC);
		return (NULL);
	}
	ft_strcpy(ret->av, av);
	ret->selected = 0;
	ret->curr = 0;
	ret->pos[0] = 0;
	ret->pos[1] = 0;
	ret->offset = 0;
	ret->prev = NULL;
	ret->next = NULL;
	return (ret);
}

int			s_init(t_select **select, const char **av)
{
	t_select		*node;
	unsigned int	i;

	i = 0;
	while (av[++i])
	{
		node = s_newnode(av[i]);
		if (!node)
			return (-1);
		s_addnode(select, node);
	}
	return (0);
}
