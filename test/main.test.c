/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:25:08 by agaley            #+#    #+#             */
/*   Updated: 2023/05/10 16:18:48 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	test_stack_swap();
	test_stack_push();
	test_stack_rotate();
	test_stack_rrotate();
	return (0);
}