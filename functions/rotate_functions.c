/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:06:46 by kami              #+#    #+#             */
/*   Updated: 2024/10/07 14:04:12 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

void rotate(stack **stack_ptr)
{
	if (*stack_ptr == NULL || (*stack_ptr)->next == NULL)
	{
		// Do nothing if there is only one or no elements
		return;
	}

	stack *first = *stack_ptr;
	stack *last = *stack_ptr;

	// Traverse to the last element
	while (last->next != NULL)
	{
		last = last->next;
	}

	// Update pointers to rotate the stack
	*stack_ptr = first->next;
	(*stack_ptr)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ra(stack **stack_a)
{
	rotate(stack_a);
}

void	rb(stack **stack_b)
{
	rotate(stack_b);
}

void	rr(stack **stack_a, stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
