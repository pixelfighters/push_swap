/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_obvious.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:28:34 by kami              #+#    #+#             */
/*   Updated: 2025/03/06 10:49:32 by fschuh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

void	two_sort_stack(stack **stack_a)
{
	add_command("ra");
	ra(stack_a);
}

void	three_sort_stack(stack **stack_a)
{
	while(!is_sorted(*stack_a))
	{

		
/* 		if (get_last(*stack_a)->data < (*stack_a)->data && (*stack_a)->data < (*stack_a)->next->data)
		{

			add_command("rra");
			rra(stack_a);
		}
		else if (get_last(*stack_a)->data > (*stack_a)->data && (*stack_a)->data < (*stack_a)->next->data)
		{
				add_command("sa");
				add_command("ra");
				sa(stack_a);
				ra(stack_a);
		}
		else if (get_last(*stack_a)->data > (*stack_a)->data && (*stack_a)->data > (*stack_a)->next->data)
		{
				add_command("sa");
				sa(stack_a);
		}
		else if (get_last(*stack_a)->data < (*stack_a)->data && (*stack_a)->data > (*stack_a)->next->data)
		{
				add_command("sa");
				add_command("rra");
				sa(stack_a);
				rra(stack_a);		
		} */
	}
}
void five_sort_stack(stack **stack_a, stack **stack_b)
{
	stack *current;
	int position;

	if (!stack_a || !*stack_a || !stack_b)
		return;
	
	add_command("pb");
	add_command("pb");
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	three_sort_stack(stack_a);
	if (*stack_b && (*stack_b)->next && (*stack_b)->data < (*stack_b)->next->data)
		{
			add_command("sb");
			sb(stack_b);
		}
	while (*stack_b)
	{
		current = *stack_a;
		position = 0;

		int half_size = (get_stack_size(*stack_a)) / 2;

		while (current && current->data < (*stack_b)->data)
		{
			current = current->next;
			position++;
		}

		if (position <= half_size)
		{
			while (position--)
				{
					add_command("ra");
					ra(stack_a);
				}
		}
		else
		{
			position = get_stack_size(*stack_a) - position;
			while (position--)
			{
				add_command("rra");
				rra(stack_a);
			}
		}
		add_command("pa");
		pa(stack_a, stack_b);
		while ((*stack_a)->data > get_last(*stack_a)->data)
			{
				add_command("ra");
				ra(stack_a);
			}
    }
}
