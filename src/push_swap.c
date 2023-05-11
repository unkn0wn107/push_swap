/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:41:58 by agaley            #+#    #+#             */
/*   Updated: 2023/05/11 19:04:16 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*str;
	t_stack	*stack_a;

	if (argc < 2)
		exit_error(2, (t_stack *) NULL);
	str = ft_realloc(NULL, 1);
	str = parse_args(str, argv);
	stack_a = stack_init();
	fill_stack(str, stack_a);
	str = apply_algo(select_algo(stack_a), stack_a);
	if (check_result(stack_a) != 0)
		exit_error(40, stack_a);
	stack_free(stack_a);
	ft_printf("%s\n", str);
	exit (0);
}
