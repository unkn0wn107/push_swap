/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:41:58 by agaley            #+#    #+#             */
/*   Updated: 2023/05/09 02:15:51 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	check_error(char *str)
// {
// 	if ()
// }

static int	exit_error(int code)
{
	char	*msg;

	if (code == 1)
		msg = "Memory allocation error";
	if (code == 2)
		msg = "Args error : Not enough args";
	if (code == 3)
		msg = "Args error : Duplicate entries";
	if (code == 4)
		msg = "Args error : Not a valid integer";
	ft_printf("%s\n", msg);
	exit (1);
}

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

// void	fill_stack(char *str, t_stack *stack_a)
// {
// 	int		i;
// 	char	**arr;
// 	t_node	*node;

// 	i = 0;
// 	arr = ft_split(str, ' ');
// 	while (arr[i])
// 	{
// 		node = malloc(sizeof(t_node));
// 		node->addr =
// 		stack_add(stack_a, ft_atoi(arr[i++])); // ft_atoll to be implemented
// 	}
// }

void	fill_stack(char *str, t_stack *stack_a)
{
 	int		i;
	int		num;
	char	**arr;

	(void)stack_a;
	i = 0;
	arr = ft_split(str, ' ');
	while (arr[i])
	{
		num = ft_atoi(arr[i]);
		printf("%d\n", INT_MIN);
		// num < INT_MIN || num > INT_MAX : how to check
		if (num == 0 && !ft_strchr(arr[i], '0'))
			exit_error(4);
		ft_printf("%d\n", num); // ft_atoll to be implemented
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	t_stack	*stack_a;
	// t_stack	stack_b;

	if (argc < 2)
		exit_error(2);
	str = ft_realloc(NULL, 1);
	str = parse_args(str, argv);
	ft_printf("%s\n", str);
	stack_a = stack_init();
	fill_stack(str, stack_a);
	//check_duplicates(stack_a);
	//select_algo(stack_a);
	//stack_b = stack_init();
	//apply_algo(stack_a, &stack_b);
	//print_result(stack_a);
	//free_stacks(stack_a, &stack_b);
	exit (0);
}
