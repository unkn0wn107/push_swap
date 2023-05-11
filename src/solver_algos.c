/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_algos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:57:49 by agaley            #+#    #+#             */
/*   Updated: 2023/05/12 01:20:39 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_3(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a->head->value > stack_a->head->next->value)
		stack_swap(stack_a);
	else
		stack_rrotate(stack_a);
}

void	algo_5(t_stack *stack1, t_stack *stack2)
{
	(void)stack1;
	(void)stack2;
}

void	algo_100(t_stack *stack1, t_stack *stack2)
{
	(void)stack1;
	(void)stack2;
}

void	algo_500(t_stack *stack1, t_stack *stack2)
{
	(void)stack1;
	(void)stack2;
}

void	algo_500_plus(t_stack *stack1, t_stack *stack2)
{
	(void)stack1;
	(void)stack2;
}
