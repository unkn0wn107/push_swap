/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:50:17 by agaley            #+#    #+#             */
/*   Updated: 2023/05/16 01:01:31 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exit_error(int code, t_stack *stack)
{
	char	*msg;

	if (code == 10)
		msg = "Memory allocation error";
	if (code == 11)
		msg = "Stack doesn't exist";
	if (code == 20)
		msg = "Args error : Not enough args";
	if (code == 21)
		msg = "Args error : Duplicate entries";
	if (code == 22)
		msg = "Args error : Not a valid integer";
	if (code == 30)
		msg = "Stack error : Adding to empty stack";
	if (code == 31)
		msg = "Stack error : Duplicate entries";
	if (code == 40)
		msg = "Algo error : Stack is not sorted";
	if (code == 41)
		msg = "Algo error : Algo not found";
	ft_printf("%s\n", msg);
	stack_free(stack);
	exit (1);
}
