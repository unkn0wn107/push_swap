/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_push.test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:56:32 by agaley            #+#    #+#             */
/*   Updated: 2023/05/10 02:10:37 by agaley           ###   ########lyon.fr   */
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
// int	stack_push(t_stack *stack1, t_stack *stack2)
// {
// 	t_node	*node1;
// 	t_node	*node2;

// 	if (!stack1 || !stack2)
// 		return (-1);
// 	node1 = stack1->head;
// 	if (!node1)
// 		return (1);
// 	node2 = stack2->head;
// 	stack2->head = node1;
// 	stack1->head = node1->next;
// 	node1->next = node2;
// 	return (0);
// }
