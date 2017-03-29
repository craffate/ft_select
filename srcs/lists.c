/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 01:05:48 by craffate          #+#    #+#             */
/*   Updated: 2017/03/29 06:44:43 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
		*select = node;
		return ;
	}
	tmp = *select;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = node;
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
