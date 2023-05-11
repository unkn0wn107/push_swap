/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:56:32 by agaley            #+#    #+#             */
/*   Updated: 2023/05/12 00:46:59 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

// Protection check
// Stack free check
// One node + stack free check
// 3 nodes + stack free check
int	test_stack_free(void)
{
	t_stack	*stack;
	t_node	node;

	node.value = 1;
	stack = NULL;
	stack_free(stack);
	stack = stack_init('a');
	stack_free(stack);
	stack = stack_init('a');
	stack_add(stack, node);
	stack_free(stack);
	stack = stack_init('a');
	stack_add(stack, node);
	stack_add(stack, node);
	stack_add(stack, node);
	stack_free(stack);
	if (stack)
		return (ft_printf("stack_free : didn't free stack\n"), -1);
	return (printf("stack_free: OK\n"), 0);
}

// -1 if stack is NULL
// 1 if stack has less than 2 nodes
// 0 otherwise
// Swap first and second nodes and verify result
int	test_stack_swap(void)
{
	t_stack	*stack;
	t_node	node1;
	t_node	node2;

	node1.value = 1;
	node2.value = 2;
	stack = NULL;
	if (stack_swap(stack) != -1)
		return (ft_printf("stack_swap : doesn't return -1 on NULL\n"), -1);
	stack = stack_init('a');
	if (stack_swap(stack) != 1)
		return (ft_printf("stack_swap : doesn't return 1 for one elem\n"), -1);
	stack_add(stack, node1);
	if (stack_swap(stack) != 1)
		return (ft_printf("stack_swap : doesn't return 1 for one elem\n"), -1);
	stack_add(stack, node2);
	if (stack_swap(stack) != 0)
		return (ft_printf("stack_swap : doesn't return 0 for success\n"), -1);
	if (stack->head->value != 1 || stack->head->next->value != 2)
		return (ft_printf("stack_swap : doesn't swap nodes\n"), -1);
	stack_free(stack);
	printf("stack_swap: OK\n");
	return (0);
}

// -1 if one or both stacks is NULL
// 1 if stack has less than 2 nodes
// 0 otherwise
// Push first node of stack 1 to stack 2 and verify result
int	test_stack_push(void)
{
	t_stack	*stack1;
	t_stack	*stack2;
	t_node	node;

	node.value = 1;
	if (stack_push(NULL, NULL) != -1)
		return (ft_printf("stack_push : no return -1 on NULL, NULL\n"), -1);
	stack1 = stack_init('a');
	if (stack_push(stack1, NULL) != -1)
		return (ft_printf("stack_push : no return -1 on NULL stack 1\n"), -1);
	if (stack_push(NULL, stack1) != -1)
		return (ft_printf("stack_push : no return -1 on NULL stack 2\n"), -1);
	stack2 = stack_init('b');
	if (stack_push(stack1, stack2) != 1)
		return (ft_printf("stack_push : no return 1 for empty stack 1\n"), -1);
	stack_add(stack1, node);
	if (stack_push(stack1, stack2) != 0)
		return (ft_printf("stack_push : no return 0 for success\n"), -1);
	if (stack2->head->value != 1 || stack1->head != NULL)
		return (ft_printf("stack_push : doesn't push nodes\n"), -1);
	stack_free(stack1);
	stack_free(stack2);
	printf("stack_push: OK\n");
	return (0);
}

// -1 if stack is NULL
// 1 if stack has less than 2 nodes
// 0 otherwise
// Rotate stack and verify result
int	test_stack_rotate(void)
{
	t_stack	*stack;
	t_node	node1;
	t_node	node2;
	t_node	node3;

	node1.value = 1;
	node2.value = 2;
	node3.value = 3;
	if (stack_rotate(NULL) != -1)
		return (ft_printf("stack_rotate : no return -1 on NULL\n"), -1);
	stack = stack_init('a');
	if (stack_rotate(stack) != 1)
		return (ft_printf("stack_rotate : no return 1 if stack < 2n\n"), -1);
	stack_add(stack, node1);
	if (stack_rotate(stack) != 1)
		return (ft_printf("stack_rotate : no return 1 if stack < 2n\n"), -1);
	stack_add(stack, node2);
	stack_add(stack, node3);
	if (stack_rotate(stack) != 0)
		return (ft_printf("stack_rotate : no return 0 for success\n"), -1);
	if (stack->head->value != 2 || stack->head->next->value != 1
		|| stack->head->next->next->value != 3)
		return (ft_printf("stack_rotate : doesn't rotate nodes\n"), -1);
	stack_free(stack);
	printf("stack_rotate: OK\n");
	return (0);
}

// -1 if stack is NULL
// 1 if stack has less than 2 nodes
// 0 otherwise
// Reverse rotate stack and verify result
int	test_stack_rrotate(void)
{
	t_stack	*stack;
	t_node	node1;
	t_node	node2;
	t_node	node3;

	node1.value = 1;
	node2.value = 2;
	node3.value = 3;
	if (stack_rrotate(NULL) != -1)
		return (ft_printf("stack_rrotate : no return -1 on NULL\n"), -1);
	stack = stack_init('a');
	if (stack_rrotate(stack) != 1)
		return (ft_printf("stack_rrotate : no return 1 if stack < 2n\n"), -1);
	stack_add(stack, node1);
	if (stack_rrotate(stack) != 1)
		return (ft_printf("stack_rrotate : no return 1 if stack < 2n\n"), -1);
	stack_add(stack, node2);
	stack_add(stack, node3);
	if (stack_rrotate(stack) != 0)
		return (ft_printf("stack_rrotate : no return 0 for success\n"), -1);
	if (stack->head->value != 1 || stack->head->next->value != 3
		|| stack->head->next->next->value != 2)
		return (ft_printf("stack_rrotate : doesn't rotate nodes\n"), -1);
	stack_free(stack);
	printf("stack_rrotate: OK\n");
	return (0);
}
