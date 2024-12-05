/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:06:46 by kami              #+#    #+#             */
/*   Updated: 2024/12/04 15:57:14 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

void	push(stack **stack_from_ptr, stack **stack_to_ptr)
{
	stack	*push_value;

	push_value = *stack_from_ptr;
	if (*stack_from_ptr == NULL)
		ft_errhandle("Error msg - nothing in from_stack\n");
	// oberes item von stack_from_ptr nehmen
	*stack_from_ptr = (*stack_from_ptr)->next;
	if (*stack_from_ptr != NULL)
		(*stack_from_ptr)->prev = NULL;
	// zu stack_to_ptr hunzufügen
	push_value->next = *stack_to_ptr;
	if (*stack_to_ptr != NULL)
		(*stack_to_ptr)->prev = push_value;
	*stack_to_ptr = push_value;
	// printf("Pushed value is: %d\n", push_value->data);
}

void	pa(stack **stack_a, stack **stack_b, instruction **instructions)
{
	add_instruction(instructions, "pa");
	push(stack_b, stack_a);
}

void	pb(stack **stack_a, stack **stack_b, instruction **instructions)
{
	add_instruction(instructions, "pb");
	push(stack_a, stack_b);
}
