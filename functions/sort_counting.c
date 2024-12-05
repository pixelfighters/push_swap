/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_counting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:28:34 by kami              #+#    #+#             */
/*   Updated: 2024/12/04 16:11:05 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

// Function to get the maximum value in the stack
int get_max_value(stack *stack_a)
{
	int max = stack_a->data;
	while (stack_a) {
		if (stack_a->data > max) 
		{
			max = stack_a->data;
		}
		stack_a = stack_a->next;
	}
	return max;
}

// Counting Sort implementation using stack operations
void counting_sort_stack(stack **stack_a, stack **stack_b, instruction **instructions)
{
	counting_sort_vars vars;

vars.max_value = get_max_value(*stack_a);
vars.size = 0;
vars.temp = *stack_a;

// Get the size of the stack
while (vars.temp)
{
    vars.size++;
    vars.temp = vars.temp->next;
}

int *count = calloc(vars.max_value + 1, sizeof(int));
if (!count)
{
    ft_errhandle("Error: Memory allocation failed\n");
}

while (*stack_a) {
    count[(*stack_a)->data]++;
    pb(stack_a, stack_b, instructions);
}

// Push elements back to stack_a in sorted order (high to low)
for (vars.i = vars.max_value; vars.i >= 0; vars.i--)
{
    while (count[vars.i] > 0)
    {
        // Find the element in stack_b and push it to stack_a
        vars.temp = *stack_b;
        while (vars.temp && vars.temp->data != vars.i)
        {
            rb(stack_b, instructions);
            vars.temp = *stack_b;
        }
        if (vars.temp && vars.temp->data == vars.i)
        {
            pa(stack_a, stack_b, instructions);
            count[vars.i]--;\
        }
    }
}
free(count);
}