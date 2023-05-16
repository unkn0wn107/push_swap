/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_adapter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:53:05 by agaley            #+#    #+#             */
/*   Updated: 2023/05/16 01:44:51 by agaley           ###   ########lyon.fr   */
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
	if (stack_a->head)
		stack_set_asc_index(stack_a);
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

/**
 * Set index of nodes in a stack
 *
 * @param stack pointer towards stack anchor
 */
void	stack_set_asc_index(t_stack *stack)
{
	t_node	*node;
	size_t	i;

	i = 0;
	node = stack_min_value(stack);
	while (node)
	{
		node->index = i++;
		node = stack_next_min_value(stack, node->value);
	}
}

/**
 * Return node with the minimum value in a stack
 *
 * @param stack pointer towards stack anchor
 * @return node with minimum in stack
 */
t_node	*stack_min_value(t_stack *stack)
{
	t_node	*node;
	t_node	*min;

	node = stack->head;
	if (!node)
		return (NULL);
	min = node;
	while (node)
	{
		if (node->value < min->value)
			min = node;
		node = node->next;
	}
	return (min);
}

/**
 * Return node with the next minimum value in a stack
 *
 * @param stack pointer towards stack anchor
 * @param value value of current node
 * @return node with minimum in stack or NULL if none
 */
t_node	*stack_next_min_value(t_stack *stack, long long int value)
{
	t_node	*node;
	t_node	*min;

	node = stack->head;
	min = NULL;
	while (node)
	{
		if (node->value > value
			&& (!min || node->value < min->value))
			min = node;
		node = node->next;
	}
	return (min);
}
