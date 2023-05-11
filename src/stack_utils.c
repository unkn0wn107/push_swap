/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:56:32 by agaley            #+#    #+#             */
/*   Updated: 2023/05/11 18:48:25 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Initialize stack anchor
 * @return t_stack* or NULL if malloc fails
 */
t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	return (stack);
}

/**
 * Adds an element to a stack
 * @param stack pointer towards stack anchor
 * @param new_addr the address of the allocated item
 */
void	stack_add(t_stack *stack, t_node node)
{
	t_node	*new;

	if (stack == NULL)
		exit_error(30, (t_stack *) NULL);
	new = (t_node *)malloc(sizeof(*new));
	if (new == NULL)
		exit_error(10, stack);
	new->value = node.value;
	new->next = stack->head;
	stack->head = new;
}

/**
 * Removes last element from a stack
 * @param stack pointer towards stack anchor
 */
void	stack_pop(t_stack *stack)
{
	t_node	*popped;

	if (stack == NULL)
		exit_error(30, stack);
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
	while (stack && stack->head)
		stack_pop(stack);
	if (stack)
		free(stack);
}
