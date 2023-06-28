/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:41:58 by agaley            #+#    #+#             */
/*   Updated: 2023/06/28 17:57:35 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*input_list;
	t_stack	stack_a;

	if (argc < 2)
		exit_error(20, (t_stack *) NULL);
	input_list = parse_args(argv);
	stack_a.id = 'a';
	stack_a.head = NULL;
	fill_stack(input_list, &stack_a);
	free(input_list);
	solve(&stack_a);
	stack_free(&stack_a);
	exit (0);
}
