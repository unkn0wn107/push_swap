/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_push.test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:56:32 by agaley            #+#    #+#             */
/*   Updated: 2023/05/10 14:17:41 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_stack_swap(void)
{
	int		response;
	t_stack	*stack;
	t_node	node1;
	t_node	node2;

	node1.value = 1;
	node2.value = 2;
	stack = NULL;
	response = stack_swap(stack);
	if (response != -1) // -1 if stack is NULL
		return (ft_printf("stack_swap : doesn't return -1 on NULL\n"), -1);
	stack = stack_init();
	response = stack_swap(stack);
	if (response != 1) // 1 if stack has less than 2 nodes
		return (ft_printf("stack_swap : doesn't return 1 for one elem\n"), -1);
	stack_add(stack, node1);
	response = stack_swap(stack);
	if (response != 1) // 1 if stack has less than 2 nodes
		return (ft_printf("stack_swap : doesn't return 1 for one elem\n"), -1);
	stack_add(stack, node2);
	response = stack_swap(stack);
	if (response != 0) // 0 if stack has 2 or more nodes
		return (ft_printf("stack_swap : doesn't return 0 for success\n"), -1);
	if (stack->head->value != 1 || stack->head->next->value != 2)
		return (ft_printf("stack_swap : doesn't swap nodes\n"), -1);
	stack_pop(stack);
	stack_pop(stack);
	if (stack->head != NULL)
		return (ft_printf("stack_swap : nodes not popped properly\n"), -1);
	printf("stack_swap: OK\n");
	return (0);
}

/**
 * Push first node of stack1 to stack2
 *
 * @param stack1 pointer towards stack1 anchor
 * @param stack2 pointer towards stack2 anchor
 * @return -1 if a stack is NULL, 1 if stack1 is empty, 0 otherwise
 */
int	test_stack_push(void)
{
	int		response;
	t_stack	*stack1;
	t_stack	*stack2;
	t_node	node;

	node.value = 1;
	response = stack_push(NULL, NULL);
	if (response != -1) // -1 if stack is NULL
		return (ft_printf("stack_push : doesn't return -1 on NULL, NULL\n"), -1);
	stack1 = stack_init();
	response = stack_push(stack1, NULL);
	if (response != -1) // -1 if stack is NULL
		return (ft_printf("stack_push : doesn't return -1 on NULL stack 1\n"), -1);
	response = stack_push(NULL, stack1);
	if (response != -1) // -1 if stack is NULL
		return (ft_printf("stack_push : doesn't return -1 on NULL stack 2\n"), -1);
	stack2 = stack_init();
	response = stack_push(stack1, stack2);
	if (response != 1) // 1 if stack 1 is empty
		return (ft_printf("stack_push : doesn't return 1 for empty stack 1\n"), -1);
	stack_add(stack1, node);
	response = stack_push(stack1, stack2);
	if (stack2->head->value != 1 || stack1->head != NULL)
		return (ft_printf("stack_push : doesn't push nodes\n"), -1);
	if (response != 0) // 0 if success
		return (ft_printf("stack_push : doesn't return 0 for success\n"), -1);
	stack_pop(stack2);
	if (stack2->head != NULL)
		return (ft_printf("stack_push : nodes not popped properly\n"), -1);
	printf("stack_push: OK\n");
	return (0);
}
