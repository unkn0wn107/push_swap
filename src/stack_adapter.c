/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_adapter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:53:05 by agaley            #+#    #+#             */
/*   Updated: 2023/05/11 18:47:47 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO : ft_atoll to be implemented
void	fill_stack(char *str, t_stack *stack_a)
{
	size_t				i;
	long long int		num;
	char				**arr;
	t_node				node;

	i = 0;
	arr = ft_split(str, ' ');
	while (arr[i])
		i++;
	while (i--)
	{
		num = ft_atoi(arr[i]);
		if ((num == 0 && !ft_strchr(arr[i], '0'))
			|| ft_strncmp(ft_itoa(num), arr[i], ft_strlen(arr[i])) != 0)
			exit_error(22, stack_a);
		if (stack_get_node(stack_a, num))
			exit_error(21, stack_a);
		node.value = num;
		stack_add(stack_a, node);
	}
}

/**
 * Return node with value in a stack
 *
 * @param stack pointer towards stack anchor
 * @param value value of node
 * @return first node in stack
 */
t_node	*stack_get_node(t_stack *stack, long long int value)
{
	t_node	*node;

	node = stack->head;
	while (node)
	{
		if (node->value == value)
			return (node);
		node = node->next;
	}
	return (NULL);
}
