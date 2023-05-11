/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:57:49 by agaley            #+#    #+#             */
/*   Updated: 2023/05/11 23:18:03 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*algo_3(t_stack *s1, t_stack *s2)
{
	long long int	n1;
	long long int	n2;
	long long int	n3;	

	n1 = s1->head->value;
	n2 = s1->head->next->value;
	n3 = s1->head->next->next->value;
	(void)s2;
	if (stack_size(s1) == 2 && n1 > n2)
		return (stack_swap(s1), " ");
	else if (n1 > n2 && n1 < n3)
		stack_swap(s1);
	else if (n1 > n2 && n1 > n3)
		stack_rotate(s1);
	else if (n1 > n2 && n2 < n3)
		stack_rotate(s1);
	else if (n1 > n2 && n2 > n3)
		return (stack_swap(s1), stack_rrotate(s1), " ");
	else if (n1 < n2 && n1 > n3)
		return (stack_rrotate(s1), " ");
	else if (n1 < n2 && n2 > n3)
		return (stack_swap(s1), stack_rotate(s1), " ");
	return (" ");
}

char	*algo_5(t_stack *stack1, t_stack *stack2)
{
	(void)stack1;
	(void)stack2;
	return (" ");
}

char	*algo_100(t_stack *stack1, t_stack *stack2)
{
	(void)stack1;
	(void)stack2;
	return (" ");
}

char	*algo_500(t_stack *stack1, t_stack *stack2)
{
	(void)stack1;
	(void)stack2;
	return (" ");
}

char	*algo_500_plus(t_stack *stack1, t_stack *stack2)
{
	(void)stack1;
	(void)stack2;
	return (" ");
}
