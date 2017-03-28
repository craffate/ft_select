/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackrrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:31:14 by craffate          #+#    #+#             */
/*   Updated: 2017/03/26 04:24:46 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackrrotate(t_stack *stack)
{
	int		i;
	size_t	j;

	if (stack->head < 2)
		return ;
	i = stack->data[0];
	j = -1ul;
	while (++j < stack->head - 1)
		stack->data[j] = stack->data[j + 1];
	stack->data[stack->head - 1] = i;
}
