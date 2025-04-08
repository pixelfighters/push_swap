/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:21:23 by kami              #+#    #+#             */
/*   Updated: 2025/04/08 17:03:06 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
#include <ctype.h>

# define MAX_COMMANDS 500

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_stack;

// Function prototypes

char **ft_checkargs(int argc, char **argv);
void		ft_flattenargs(int argc, char **argv);
int	ft_arraylength(int argc, char **argv);
int		ft_count(int argc, t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack_a);
void	free_list(t_stack *stack);
t_stack	*ft_last_item(t_stack *stack);
int		read_bits(t_stack **stack);
int		stack_size(t_stack *stack_a);
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	init_index(t_stack *stack);
void	sort_radix(t_stack **stack_a, t_stack **stack_b);
int find_biggest(t_stack *stack);
int find_smallest(t_stack *stack);
void push_to_top(t_stack **stack, int value);
int find_position(t_stack *stack, int value);
void push_to_correct_position(t_stack **stack_a, int value);
void push_chunk_to_stack_b(t_stack **stack_a, t_stack **stack_b, int start, int end);
void turk_sort(t_stack **stack_a, t_stack **stack_b);
int find_position_in_chunk(t_stack *stack, int start, int end);


void	print_list(t_stack *stack_a);
t_stack	*fill_node(int argc, char **argv);

void	rotate(t_stack **stack_ptr);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	reverse_rotate(t_stack **stack_ptr);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	swap_top_two(t_stack **stack_ptr);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	push(t_stack **stack_from_ptr, t_stack **stack_to_ptr);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
#endif 