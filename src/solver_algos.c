/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_algos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:57:49 by agaley            #+#    #+#             */
/*   Updated: 2023/05/16 02:35:31 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_3(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a->head->index > stack_a->head->next->index)
		stack_swap(stack_a);
	else
		stack_rrotate(stack_a);
}

void	algo_5(t_stack *stack_a, t_stack *stack_b)
{
	algo_radix(stack_a, stack_b);
}

void	algo_radix(t_stack *stack_a, t_stack *stack_b)
{
	size_t	size;
	size_t	i;
	size_t	bit;

	size = stack_size(stack_a);
	bit = 1;
	i = 0;
	while (bit <= (size - 1))
	{
		i = 0;
		while (i < size)
		{
			if (!(stack_a->head->index & bit))
				stack_push(stack_a, stack_b);
			else
				stack_rotate(stack_a);
			i++;
		}
		while (stack_b->head)
		{
			stack_push(stack_b, stack_a);
		}
		bit = bit << 1;
	}
}
