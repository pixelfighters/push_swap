/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simples.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:31:14 by fschuh            #+#    #+#             */
/*   Updated: 2025/03/12 15:01:13 by fschuh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	ra(stack_a);
}

void	sort_three(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) == 3)
		pb(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		sort_two(stack_a);
	if ((*stack_b)->value < (*stack_a)->value)
		pa(stack_a, stack_b);
	else if ((*stack_b)->value > ft_last_item(*stack_a)->value)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if ((*stack_b)->value < ft_last_item(*stack_a)->value)
	{
		ra(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) == 4)
		pb(stack_a, stack_b);
	sort_three(stack_a, stack_b);
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
	if (stack_size(*stack_a) == 5)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a, stack_b);
	while (*stack_b != NULL)
	{
		if ((*stack_b)->value < (*stack_a)->value)
			pa(stack_a, stack_b);
		else if ((*stack_b)->value > ft_last_item(*stack_a)->value)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else
		{
			ra(stack_a);
			pa(stack_a, stack_b);
			rra(stack_a);
		}
	}
}

int	ft_count(int argc, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (!is_sorted(*stack_a) && i <= MAX_COMMANDS)
	{
		if (argc == 3)
			sort_two(stack_a);
		else if (argc == 4)
			sort_three(stack_a, stack_b);
		else if (argc == 5)
			sort_four(stack_a, stack_b);
		else if (argc == 6)
			sort_five(stack_a, stack_b);
		else
			ft_printf("anzahl big");
		i++;
	}
	return (0);
}
