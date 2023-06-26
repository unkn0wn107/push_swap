/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:41:58 by agaley            #+#    #+#             */
/*   Updated: 2023/06/16 18:04:49 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*input_list;
	t_stack	stack_a;

	if (argc < 2)
		exit_error(20, (t_stack *) NULL);
	input_list = ft_realloc(NULL, 1);
	input_list = parse_args(input_list, argv);
	stack_a.id = 'a';
	stack_a.head = NULL;
	fill_stack(input_list, &stack_a);
	solve(&stack_a);
	stack_free(&stack_a);
	exit (0);
}
