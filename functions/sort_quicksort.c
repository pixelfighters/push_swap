/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:28:34 by kami              #+#    #+#             */
/*   Updated: 2024/12/05 15:28:16 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

void quick_sort_stack(stack **stack_a, stack **stack_b)
{
    int size;

    // Get the size of stack_a
    size = get_stack_size(*stack_a);

    // Call the quick sort helper with the calculated size
    quick_sort_stack_helper(stack_a, stack_b, size);
}

void quick_sort_stack_helper(stack **stack_a, stack **stack_b, int size)
{
    if (size <= 1)
        return;

    int pivot = choose_pivot(*stack_a); // Pick a pivot element
    int left_size = 0, right_size = 0;

    // Step 1: Partition the stack based on the pivot
    for (int i = 0; i < size; i++)
    {
        if ((*stack_a)->data <= pivot)
        {
            pb(stack_a, stack_b);  // Move smaller elements to stack_b
            left_size++;
        }
        else
        {
            ra(stack_a);  // Keep larger elements in stack_a
            right_size++;
        }
    }

    // Step 2: Recursively sort both halves
    quick_sort_stack_helper(stack_a, stack_b, right_size); // Sort right partition (larger elements)
    quick_sort_stack_helper(stack_b, stack_a, left_size);  // Sort left partition (smaller elements)

    // Step 3: Push smaller sorted elements back to stack_a
    while (left_size-- > 0)
    {
        pa(stack_a, stack_b);
    }
}

int choose_pivot(stack *stack_a)
{
    return stack_a->data;  // Simplest pivot choice: use the first element
}

int get_stack_size(stack *stack_a)
{
    int size = 0;

    while (stack_a)
    {
        size++;
        stack_a = stack_a->next;
    }

    return size;
}
