/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:51:50 by agaley            #+#    #+#             */
/*   Updated: 2023/05/12 01:16:56 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

// Integer stack definition
typedef struct s_stack_node
{
	long long int		value;
	struct s_stack_node	*next;
}t_node;

typedef struct s_stack
{
	char	id;
	t_node	*head;
}t_stack;

// Stack utils
t_stack	*stack_init(char id);
void	stack_add(t_stack *stack, t_node node);
void	stack_pop(t_stack *stack);
void	stack_free(t_stack *stack);
t_node	*stack_last(t_stack *stack);
t_node	*stack_last_n(t_stack *stack, size_t N);
t_node	*stack_get_node(t_stack *stack, long long int value);

// Stack adapter
void	fill_stack(char *str, t_stack *stack_a);
size_t	stack_size(t_stack *stack);

// Stack operations
int		stack_swap(t_stack	*stack);
int		stack_swap2(t_stack *stack1, t_stack *stack2);
int		stack_push(t_stack *stack1, t_stack *stack2);
int		stack_rotate(t_stack *stack);
int		stack_rotate2(t_stack *stack1, t_stack *stack2);
int		stack_rrotate(t_stack *stack);
int		stack_rrotate2(t_stack *stack1, t_stack *stack2);

// Algorithms
void	*select_algo(t_stack *stack);
void	algo_3(t_stack *stack1, t_stack *stack2);
void	algo_5(t_stack *stack1, t_stack *stack2);
void	algo_100(t_stack *stack1, t_stack *stack2);
void	algo_500(t_stack *stack1, t_stack *stack2);
void	algo_500_plus(t_stack *stack1, t_stack *stack2);

// Solver
void	apply_algo(void (*fun)(t_stack*, t_stack*), t_stack *stack_a);
int		check_result(t_stack *stack);

// Parser
char	*parse_args(char *str, char **argv);

// Error handlers
int		exit_error(int code, t_stack *stack);

#endif
