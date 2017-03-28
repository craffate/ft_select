/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:23:01 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 15:22:24 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack		ft_stacknew(size_t si)
{
	t_stack		stack;

	if (!(stack.data = (int *)malloc(sizeof(int) * si)))
		exit(-1);
	stack.head = 0;
	stack.si = si;
	return (stack);
}
