/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:28:34 by kami              #+#    #+#             */
/*   Updated: 2024/10/08 16:08:45 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

int	get_max_bits(stack *stack_a)
{
	int	max;
	int	bits;

	bits = 0;
	max = 0;
	while (stack_a)
	{
		if (stack_a->data > max)
			max = stack_a->data;
		stack_a = stack_a->next;
	}
	while ((max >> bits) != 0)
	{
		bits++;
	}
	return (bits);
}

void	radix_sort_stack(stack **stack_a, stack **stack_b)
{
	radix_sort_vars vars;

	vars.max_bits = get_max_bits(*stack_a);
	vars.i = 0;
	vars.size = 0;
	vars.temp = *stack_a;
	while (vars.temp) // stack size berechnen
	{
		vars.size++;
		vars.temp = vars.temp->next;
	}
	while (vars.i < vars.max_bits)
	{
		vars.j = -1;
		while (vars.j++ < vars.size)
		{
			if ((((*stack_a)->data >> vars.i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		vars.i++;
	}
}
