/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:56:32 by agaley            #+#    #+#             */
/*   Updated: 2023/06/28 18:05:12 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Adds an element to a stack
 * @param stack pointer towards stack anchor
 * @param new_addr the address of the allocated item
 */
void	stack_add(t_stack *stack, int value)
{
	t_node	*new;

	if (stack == NULL)
		exit_error(30, NULL, NULL, NULL);
	else
	{
		new = (t_node *)malloc(sizeof(t_node));
		if (new == NULL)
			exit_error(10, stack, NULL, NULL);
		else
		{
			new->value = value;
			new->next = stack->head;
			stack->head = new;
		}
	}
}

/**
 * Removes last element from a stack
 * @param stack pointer towards stack anchor
 */
void	stack_pop(t_stack *stack)
{
	t_node	*popped;

	if (stack->head)
	{
		popped = stack->head;
		stack->head = popped->next;
		free(popped);
	}
}

/**
 * Frees a stack and all elements in it
 * @param stack pointer towards stack anchor
 */
void	stack_free(t_stack *stack)
{
	while (stack->head)
		stack_pop(stack);
}
