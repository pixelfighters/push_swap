/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:40:07 by fschuh            #+#    #+#             */
/*   Updated: 2025/04/09 16:14:11 by fschuh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	read_bits(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		bits;

	head = *stack;
	max = head->index;
	bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		bits;

	i = 0;
	head_a = *stack_a;
	size = stack_size(head_a);
	bits = read_bits(stack_a);
	while (i < bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (stack_size(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
