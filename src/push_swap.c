/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:41:58 by agaley            #+#    #+#             */
/*   Updated: 2023/05/11 00:18:38 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*str;
	t_stack	*stack_a;

	if (argc < 2)
		exit_error(2);
	str = ft_realloc(NULL, 1);
	str = parse_args(str, argv);
	stack_a = stack_init();
	fill_stack(str, stack_a);
	exit (0);
}

// TODO
// select_algo(stack_a);
// stack_b = stack_init();
// apply_algo(stack_a, stack_b);
// print_result(stack_a);
// free_stacks(stack_a, stack_b);
