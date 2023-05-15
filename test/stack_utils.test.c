/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:53:27 by agaley            #+#    #+#             */
/*   Updated: 2023/05/16 00:53:30 by agaley           ###   ########lyon.fr   */
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
	return (printf("stack_free: OK\n"), 0);
}
