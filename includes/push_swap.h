/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:21:23 by kami              #+#    #+#             */
/*   Updated: 2024/10/09 14:50:32 by fschuh           ###   ########.fr       */
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

// Function prototypes
void	swap_top_two(stack **stack);
void	sa(stack **stack_a);
void	sb(stack **stack_b);
void	ss(stack **stack_a, stack **stack_b);
void	push(stack **stack_from_ptr, stack **stack_to_ptr);
void	pa(stack **stack_b, stack **stack_a);
void	pb(stack **stack_a, stack **stack_b);
void	rotate(stack **stack_ptr);
void	ra(stack **stack_a);
void	rb(stack **stack_b);
void	rr(stack **stack_a, stack **stack_b);
void	reverse_rotate(stack **stack_ptr);
void	rra(stack **stack_a);
void	rrb(stack **stack_b);
void	rrr(stack **stack_a, stack **stack_b);
void	print_stack(stack *stack_a);
stack	*create_node(int data);
stack	*clone_stack(stack *stack_a);
void	ft_checkdigit(char *str);
void	ft_checkargs(int argc, char **argv);
void	radix_sort_stack(stack **stack_a, stack **stack_b);
void	counting_sort_stack(stack **stack_a, stack **stack_b);
void	bubble_sort_stack(stack **stack_a, stack **stack_b);
void	merge_sort_stack(stack **stack_a, stack **stack_b, int size);
void	merge_stacks(stack **stack_a, stack **stack_b, int left_size, int right_size);
int		get_max_bits(stack *stack_a);
int		choose_pivot(stack *stack_a);
void	quick_sort_stack(stack **stack_a, stack **stack_b);
void quick_sort_stack_helper(stack **stack_a, stack **stack_b, int size);
int choose_pivot(stack *stack_a);
int get_stack_size(stack *stack_a);
/*
PUSHFUNCTIONS
ROTATEFUNCTIONS
REVERSEROTATEFUNCTIONS */

#endif 