/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:33:21 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 14:35:21 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackswap(t_stack *stack)
{
	int		i;

	if (stack->head < 2)
		return ;
	i = stack->data[stack->head - 1];
	stack->data[stack->head - 1] = stack->data[stack->head - 2];
	stack->data[stack->head - 2] = i;
}
