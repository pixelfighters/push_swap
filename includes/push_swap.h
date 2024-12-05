/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:21:23 by kami              #+#    #+#             */
/*   Updated: 2024/12/04 16:14:55 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

// Define the stack node structure
typedef struct stack
{
	int				data;
	struct stack	*next;
	struct stack	*prev;
}	stack;

typedef struct s_sort_vars
{
    int max_bits;
    int i;
    int j;
    int size;
    stack *temp;
} radix_sort_vars;

typedef struct s_counting_sort_vars
{
    int max_value;
    int i;
    int j;
    int size;
    stack *temp;
} counting_sort_vars;

typedef struct s_instruction
{
	char					*command;
	struct s_instruction	*next;
} instruction;

// Function prototypes
void	add_instruction(instruction **instructions, const char *command);
void	execute_instructions(instruction *instructions, stack **stack_a, stack **stack_b);
void	swap_top_two(stack **stack);
void	sa(stack **stack_a, instruction **instructions);
void	sb(stack **stack_b, instruction **instructions);
void	ss(stack **stack_a, stack **stack_b, instruction **instructions);
void	push(stack **stack_from_ptr, stack **stack_to_ptr);
void	pa(stack **stack_b, stack **stack_a, instruction **instructions);
void	pb(stack **stack_a, stack **stack_b, instruction **instructions);
void	rotate(stack **stack_ptr);
void	ra(stack **stack_a, instruction **instructions);
void	rb(stack **stack_b, instruction **instructions);
void	rr(stack **stack_a, stack **stack_b, instruction **instructions);
void	reverse_rotate(stack **stack_ptr);
void	rra(stack **stack_a, instruction **instructions);
void	rrb(stack **stack_b, instruction **instructions);
void	rrr(stack **stack_a, stack **stack_b, instruction **instructions);
void	two_sort_stack(stack **stack_a, instruction **instructions);
void	three_sort_stack(stack **stack_a, instruction **instructions);
void	five_sort_stack(stack **stack_a, stack **stack_b, instruction **instructions);
void	print_stack(stack *stack_a);
stack	*create_node(int data);
stack	*clone_stack(stack *stack_a);
void	ft_checkdigit(char *str);
void	ft_checkargs(int argc, char **argv);
void	radix_sort_stack(stack **stack_a, stack **stack_b, instruction **instructions);
void	counting_sort_stack(stack **stack_a, stack **stack_b, instruction **instructions);
int		get_max_bits(stack *stack_a);
/*
PUSHFUNCTIONS
ROTATEFUNCTIONS
REVERSEROTATEFUNCTIONS */

#endif 