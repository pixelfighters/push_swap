/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:28:34 by kami              #+#    #+#             */
/*   Updated: 2024/10/09 14:45:25 by fschuh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

void merge_sort_stack(stack **stack_a, stack **stack_b, int size)
{
    int mid;
    int i;

    if (size <= 1)
        return;

    // Step 1: Split the stack into two halves
    mid = size / 2;
    for (i = 0; i < mid; i++)
        pb(stack_a, stack_b); // push half to stack_b

    // Step 2: Recursively sort both halves
    merge_sort_stack(stack_a, stack_b, mid);          // Sort first half (stack_a)
    merge_sort_stack(stack_b, stack_a, size - mid);   // Sort second half (stack_b)

    // Step 3: Merge sorted halves
    merge_stacks(stack_a, stack_b, mid, size - mid);  // Merge both halves back into stack_a
}

void merge_stacks(stack **stack_a, stack **stack_b, int left_size, int right_size)
{
    while (left_size > 0 && right_size > 0)
    {
        // Compare the top elements of both stacks
        if ((*stack_a)->data <= (*stack_b)->data)
        {
            ra(stack_a);  // Element already in correct place, move to next
            left_size--;
        }
        else
        {
            pa(stack_a, stack_b); // Move element from stack_b to stack_a
            right_size--;
        }
    }

    // Move any remaining elements from stack_b to stack_a
    while (right_size > 0)
    {
        pa(stack_a, stack_b); // Move remaining elements from stack_b
        right_size--;
    }
}
