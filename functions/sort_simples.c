/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simples.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:31:14 by fschuh            #+#    #+#             */
/*   Updated: 2025/04/11 11:27:23 by fschuh           ###   ########.fr       */
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
	int	first;
	int	second;
	int	third;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
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

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest;
	int	second_smallest;

	smallest = find_smallest(*stack_a);
	push_to_top(stack_a, smallest);
	pb(stack_a, stack_b);
	second_smallest = find_smallest(*stack_a);
	push_to_top(stack_a, second_smallest);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	push_to_correct_position(stack_a, (*stack_b)->value);
	pa(stack_a, stack_b);
	push_to_correct_position(stack_a, (*stack_b)->value);
	pa(stack_a, stack_b);
}

int	ft_count(int argc, t_stack **stack_a, t_stack **stack_b)
{
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
		else
			sort_radix(stack_a, stack_b);
		i++;
	}
	return (0);
}
