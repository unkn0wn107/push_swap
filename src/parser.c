/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:51:30 by agaley            #+#    #+#             */
/*   Updated: 2023/06/28 16:40:38 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*parse_args(char **argv)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char));
	str[0] = '\0';
	if (!str)
		exit_error(1, (t_stack *) NULL);
	i = 1;
	while (argv[i])
	{
		str = ft_strpush(str, " ");
		if (!str)
			exit_error(1, (t_stack *) NULL);
		str = ft_strpush(str, argv[i++]);
		if (!str)
			exit_error(1, (t_stack *) NULL);
	}
	return (str);
}
