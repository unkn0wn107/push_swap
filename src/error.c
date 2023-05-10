/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:50:17 by agaley            #+#    #+#             */
/*   Updated: 2023/05/10 01:55:14 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	check_error(char *str)
// {
// 	if ()
// }

int	exit_error(int code)
{
	char	*msg;

	if (code == 10)
		msg = "Memory allocation error";
	if (code == 20)
		msg = "Args error : Not enough args";
	if (code == 21)
		msg = "Args error : Duplicate entries";
	if (code == 22)
		msg = "Args error : Not a valid integer";
	if (code == 30)
		msg = "Stack error : adding to empty stack";
	if (code == 31)
		msg = "Stack error : Duplicate entries";
	ft_printf("%s\n", msg);
	exit (1);
}
