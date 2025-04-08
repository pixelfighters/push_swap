/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simples.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:31:14 by fschuh            #+#    #+#             */
/*   Updated: 2025/04/08 19:19:12 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	if (stack_a == NULL)
		return (1);
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
void	sort_three(t_stack **stack_a)
{
	int first;
	int second;
	int third;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return;
	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = ft_last_item(*stack_a)->value;
	if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first > third)
		rra(stack_a);
	else if (first > second && second < third && first < third)
		sa(stack_a);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) == 4)
		pb(stack_a, stack_b);
	sort_three(stack_a);
	if ((*stack_b)->value < (*stack_a)->value)
		pa(stack_a, stack_b);
	else if ((*stack_b)->value > ft_last_item(*stack_a)->value)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if ((*stack_b)->value > (*stack_a)->value
		&& (*stack_b)->value < (*stack_a)->next->value)
	{
		ra(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
	}
	else if ((*stack_b)->value > (*stack_a)->next->value
		&& (*stack_b)->value < ft_last_item(*stack_a)->value)
	{
		ra(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
	}
}


void push_to_correct_position(t_stack **stack_a, int value)
{
	int position;
	t_stack *current;

	position = 0;
	current = *stack_a;

	// Find the correct position for the value
	while (current != NULL && !(current->value > value && (current->prev == NULL || current->prev->value < value)))
	{
		position++;
		current = current->next;
	}

	// Rotate to the correct position
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

int find_position(t_stack *stack, int value)
{
	int position;

	position = 0;
	while (stack != NULL)
	{
		if (stack->value == value)
			break;
		position++;
		stack = stack->next;
	}
	return (position);
}
/* void push_to_top(t_stack **stack, int value)
{
    int position;
    int size;

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
} */

void push_to_top(t_stack **stack, int value)
{
	int position = find_position(*stack, value);
	int size = stack_size(*stack);

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

int find_smallest(t_stack *stack)
{
	int smallest;

	smallest = stack->value;
	while (stack != NULL)
	{
		if (stack->value < smallest)
			smallest = stack->value;
		stack = stack->next;
	}
	return (smallest);
}

int find_biggest(t_stack *stack)
{
    int biggest;

    biggest = stack->value;
    while (stack != NULL)
    {
        if (stack->value > biggest)
            biggest = stack->value;
        stack = stack->next;
    }
    return (biggest);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
    int smallest;
    int second_smallest;

    // Push the smallest element to stack_b
    smallest = find_smallest(*stack_a);
    push_to_top(stack_a, smallest);
    pb(stack_a, stack_b);

    // Push the second smallest element to stack_b
    second_smallest = find_smallest(*stack_a);
    push_to_top(stack_a, second_smallest);
    pb(stack_a, stack_b);
//print_list(*stack_a);
    // Sort the remaining three elements in stack_a
    sort_three(stack_a);
//print_list(*stack_a);
    // Push the second smallest element back to stack_a
    push_to_correct_position(stack_a, (*stack_b)->value);
    pa(stack_a, stack_b);

    // Push the smallest element back to stack_a
    push_to_correct_position(stack_a, (*stack_b)->value);
    pa(stack_a, stack_b);
//print_list(*stack_a);
}

int	ft_count(int argc, t_stack **stack_a, t_stack **stack_b)
{
	int size;

    size = stack_size(*stack_a);
	int	i;

	i = 0;
	while (!is_sorted(*stack_a) && i <= MAX_COMMANDS)
	{
		if (argc == 2)
			ra(stack_a);
		else if (argc == 3)
			sort_three(stack_a);
		else if (argc == 4)
			sort_four(stack_a, stack_b);
		else if (argc == 5)
			sort_five(stack_a, stack_b);
		//else if (size <= 120)
		//	turk_sort(stack_a, stack_b);
		else
			sort_radix(stack_a, stack_b);
		i++;
	}
	return (0);
}
