/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_counting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:28:34 by kami              #+#    #+#             */
/*   Updated: 2024/10/08 16:33:57 by kami             ###   ########.fr       */
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
void counting_sort_stack(stack **stack_a, stack **stack_b)
{
	counting_sort_vars vars;

	vars.max_value = get_max_value(*stack_a);
	vars.size = 0;
	vars.temp = *stack_a;

	// Get the size of the stack
	while (vars.temp) {
		vars.size++;
		vars.temp = vars.temp->next;
	}

	int *count = calloc(vars.max_value + 1, sizeof(int));
	if (!count)
	{
		ft_errhandle("Error: Memory allocation failed\n");
	}

	// Count and push elements to stack_b
	while (*stack_a) {
		count[(*stack_a)->data]++;
		pb(stack_a, stack_b);
	}

	// zurück von low zu high
	vars.i = vars.max_value;
	while (vars.i >= 0)
	{
		while (count[vars.i] > 0)
		{
			pa(stack_a, stack_b);
			(*stack_a)->data = vars.i;
			count[vars.i]--;
		}
		vars.i--;
	}
	free(count);
}