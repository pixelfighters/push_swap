/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:06:46 by kami              #+#    #+#             */
/*   Updated: 2024/12/04 19:37:58 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

void	rotate(stack **stack_ptr)
{
    stack	*first;
    stack	*last;

    if (*stack_ptr == NULL || (*stack_ptr)->next == NULL)
    {
        // No rotation needed for empty stack or single element stack
        return;
    }

    first = *stack_ptr;
    last = *stack_ptr;

    // Move to the last element
    while (last->next != NULL)
        last = last->next;

    // Update pointers to rotate the stack
    *stack_ptr = first->next;
    (*stack_ptr)->prev = NULL;
    first->next = NULL;
    first->prev = last;
    last->next = first;
}

void	ra(stack **stack_a, instruction **instructions)
{
	add_instruction(instructions, "ra");
	rotate(stack_a);
}

void	rb(stack **stack_b, instruction **instructions)
{
	add_instruction(instructions, "rb");
	rotate(stack_b);
}

void	rr(stack **stack_a, stack **stack_b, instruction **instructions)
{
	add_instruction(instructions, "rr");
	rotate(stack_a);
	rotate(stack_b);
}