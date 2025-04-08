/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_merger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:15:27 by kami              #+#    #+#             */
/*   Updated: 2025/04/08 17:01:58 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

		#include "push_swap.h"


void turk_sort(t_stack **stack_a, t_stack **stack_b)
{
    int size = stack_size(*stack_a);
    int chunk_size = size / 6; // Divide into 5 chunks (adjustable)
    int current_chunk = 0;

    // Step 1: Push chunks to stack_b
    while (current_chunk < size)
    {
        int limit = current_chunk + chunk_size;
        push_chunk_to_stack_b(stack_a, stack_b, current_chunk, limit);
        current_chunk += chunk_size;
    }

    // Step 2: Push elements back to stack_a in sorted order
    while (*stack_b != NULL)
    {
        push_to_top(stack_b, find_biggest(*stack_b));
        pa(stack_a, stack_b);
    }
}

void push_chunk_to_stack_b(t_stack **stack_a, t_stack **stack_b, int start, int end)
{
    int size = stack_size(*stack_a);

    while (size--)
    {
        if ((*stack_a)->index >= start && (*stack_a)->index < end)
        {
            pb(stack_a, stack_b);
        }
        else
        {
            // Check if the target element is closer to the top or bottom
            int position = find_position_in_chunk(*stack_a, start, end);
            if (position <= stack_size(*stack_a) / 2)
                ra(stack_a); // Rotate towards the top
            else
                rra(stack_a); // Reverse rotate towards the bottom
        }
    }
}
int find_position_in_chunk(t_stack *stack, int start, int end)
{
    int position = 0;

    while (stack != NULL)
    {
        if (stack->index >= start && stack->index < end)
            break;
        position++;
        stack = stack->next;
    }
    return position;
}
