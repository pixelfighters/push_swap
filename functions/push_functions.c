/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:06:46 by kami              #+#    #+#             */
/*   Updated: 2024/10/07 13:39:59 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

void push(stack **stack_from_ptr, stack **stack_to_ptr)
{
	if (*stack_from_ptr == NULL)
	{
		ft_errhandle("Error msg - nothing in from_stack\n");
		return;
	}

	// Remove the top element from stack_from_ptr
	stack *push_value = *stack_from_ptr;
	*stack_from_ptr = (*stack_from_ptr)->next;
	if (*stack_from_ptr != NULL)
	{
		(*stack_from_ptr)->prev = NULL;
	}

	// Add the element to the top of stack_to_ptr
	push_value->next = *stack_to_ptr;
	if (*stack_to_ptr != NULL)
	{
		(*stack_to_ptr)->prev = push_value;
	}
	*stack_to_ptr = push_value;

	// printf("Pushed value is: %d\n", push_value->data);
}

void	pa(stack **stack_a, stack **stack_b)
{
	push(stack_b, stack_a);
}

void	pb(stack **stack_a, stack **stack_b)
{
	push(stack_a, stack_b);
}
