/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:27:31 by fschuh            #+#    #+#             */
/*   Updated: 2025/04/11 11:28:35 by fschuh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_correct_position(t_stack **stack_a, int value)
{
	int		position;
	t_stack	*current;

	position = 0;
	current = *stack_a;
	while (current != NULL && !(current->value > value 
			&& (current->prev == NULL || current->prev->value < value)))
	{
		position++;
		current = current->next;
	}
	if (position <= stack_size(*stack_a) / 2)
	{
		while (position-- > 0)
			ra(stack_a);
	}
	else
	{
		position = stack_size(*stack_a) - position;
		while (position-- > 0)
			rra(stack_a);
	}
}

int	find_position(t_stack *stack, int value)
{
	int	position;

	position = 0;
	while (stack != NULL)
	{
		if (stack->value == value)
			break ;
		position++;
		stack = stack->next;
	}
	return (position);
}

void	push_to_top(t_stack **stack, int value)
{
	int	position;
	int	size;

	position = find_position(*stack, value);
	size = stack_size(*stack);
	if (position <= size / 2)
	{
		while (position-- > 0)
			ra(stack);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			rra(stack);
	}
}

int	find_smallest(t_stack *stack)
{
	int	smallest;

	smallest = stack->value;
	while (stack != NULL)
	{
		if (stack->value < smallest)
			smallest = stack->value;
		stack = stack->next;
	}
	return (smallest);
}

int	find_biggest(t_stack *stack)
{
	int	biggest;

	biggest = stack->value;
	while (stack != NULL)
	{
		if (stack->value > biggest)
			biggest = stack->value;
		stack = stack->next;
	}
	return (biggest);
}
