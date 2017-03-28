/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:29:09 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 15:22:39 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackrotate(t_stack *stack)
{
	int		i;
	size_t	j;

	if (stack->head < 2)
		return ;
	i = stack->data[stack->head - 1];
	j = stack->head - 1;
	while (j > 0)
	{
		stack->data[j] = stack->data[j - 1];
		j--;
	}
	stack->data[0] = i;
}
