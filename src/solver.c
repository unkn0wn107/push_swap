/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:54:43 by agaley            #+#    #+#             */
/*   Updated: 2023/05/11 19:07:06 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*select_algo(t_stack *stack)
{
	if (stack_size(stack) <= 3)
		return (&algo_3);
	if (stack_size(stack) <= 5)
		return (&algo_5);
	if (stack_size(stack) <= 100)
		return (&algo_100);
	if (stack_size(stack) <= 500)
		return (&algo_500);
	if (stack_size(stack) > 500)
		return (&algo_500_plus);
	return (NULL);
}

char	*apply_algo(char *(*fun)(t_stack*, t_stack*), t_stack *stack_a)
{
	t_stack	*stack_b;
	char	*result;

	stack_b = stack_init();
	result = (*fun)(stack_a, stack_b);
	stack_free(stack_b);
	return (result);
}

int	check_result(t_stack *stack)
{
	t_node	*node;

	if (!stack)
		exit_error(11, (t_stack *) NULL);
	node = stack->head;
	while (node->next)
	{
		if (node->value > node->next->value)
			return (1);
		node = node->next;
	}
	return (0);
}
