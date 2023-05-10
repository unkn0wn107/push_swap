/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:51:50 by agaley            #+#    #+#             */
/*   Updated: 2023/05/10 01:03:02 by agaley           ###   ########lyon.fr   */
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
	t_node	*head;
}t_stack;

// Stack utils
t_stack	*stack_init(void);
void	stack_add(t_stack *stack, t_node node);
void	stack_pop(t_stack *stack);
t_node	*stack_head(t_stack *stack);
void	stack_free(t_stack *stack);

// Stack adapter
void	fill_stack(char *str, t_stack *stack_a);

// Stack operations
int		stack_swap(t_stack	*stack);
int		stack_swap2(t_stack *stack1, t_stack *stack2);
int		stack_push(t_stack *stack1, t_stack *stack2);

// Parser
char	*parse_args(char *str, char **argv);

// Error handlers
int		exit_error(int code);

#endif
