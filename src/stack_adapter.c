/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_adapter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:53:05 by agaley            #+#    #+#             */
/*   Updated: 2023/05/10 01:54:59 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// void	fill_stack(char *str, t_stack *stack_a)
// {
// 	int		i;
// 	char	**arr;
// 	t_node	*node;

// 	i = 0;
// 	arr = ft_split(str, ' ');
// 	while (arr[i])
// 	{
// 		node = malloc(sizeof(t_node));
// 		node->addr =
// 		stack_add(stack_a, ft_atoi(arr[i++])); // ft_atoll to be implemented
// 	}
// }

void	fill_stack(char *str, t_stack *stack_a)
{
 	int		i;
	int		num;
	char	**arr;

	(void)stack_a;
	i = 0;
	arr = ft_split(str, ' ');
	while (arr[i])
	{
		num = ft_atoi(arr[i]);
		printf("%d\n", INT_MIN);
		// num < INT_MIN || num > INT_MAX : how to check
		if (num == 0 && !ft_strchr(arr[i], '0'))
			exit_error(4);
		ft_printf("%d\n", num); // ft_atoll to be implemented
		i++;
	}
}
