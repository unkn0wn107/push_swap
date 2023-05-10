/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:51:30 by agaley            #+#    #+#             */
/*   Updated: 2023/05/10 01:55:10 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*parse_args(char *str, char **argv)
{
	int		i;

	i = 1;
	str = ft_realloc(NULL, 1);
	if (!str)
		exit_error(1);
	while (argv[i])
	{
		str = ft_strpush(str, " ");
		if (!str)
			exit_error(1);
		str = ft_strpush(str, argv[i++]);
		if (!str)
			exit_error(1);
	}
	return (str);
}
