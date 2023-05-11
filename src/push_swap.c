/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:41:58 by agaley            #+#    #+#             */
/*   Updated: 2023/05/12 00:44:32 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*input_list;
	t_stack	*stack_a;

	if (argc < 2)
		exit_error(2, (t_stack *) NULL);
	input_list = ft_realloc(NULL, 1);
	input_list = parse_args(input_list, argv);
	stack_a = stack_init('a');
	fill_stack(input_list, stack_a);
	while ((check_result(stack_a) != 0))
		apply_algo(select_algo(stack_a), stack_a);
	stack_free(stack_a);
	exit (0);
}
