/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_obvious.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:28:34 by kami              #+#    #+#             */
/*   Updated: 2024/12/05 15:02:48 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

int get_stack_size(stack *stack_x)
{
    int size = 0;

    while (stack_x)
    {
        size++;
        stack_x = stack_x->next;
    }
    return (size);
}

int get_last_element_data(stack *stack_x)
{
    while (stack_x->next != NULL)
    {
        stack_x = stack_x->next;
    }
    return (stack_x->data);
}

void	two_sort_stack(stack **stack_x, instruction **instructions)
{
    ra(stack_x, instructions);
}

void	three_sort_stack(stack **stack_x, instruction **instructions)
{
	while(!is_sorted(*stack_x))
	{
		if ((*stack_x)->data < (*stack_x)->next->data)
			sa(stack_x, instructions);
		else if ((*stack_x)->next->data < (*stack_x)->data)
			ra(stack_x, instructions);
		else
			rra(stack_x, instructions);
	}

}

void five_sort_stack(stack **stack_a, stack **stack_b, instruction **instructions)
{
    while (get_stack_size(*stack_a) > 3)
        pb(stack_a, stack_b, instructions); 
    three_sort_stack(stack_a, instructions);
	if(get_stack_size(*stack_b) == 2 && (*stack_b)->data > (*stack_b)->next->data)	
		two_sort_stack(stack_b, instructions);
	while (!is_sorted(*stack_a) || (get_stack_size(*stack_a) != 5 && (*stack_b)->data))
	{
		if ((*stack_b)->data < (*stack_a)->data)
			pa(stack_a, stack_b, instructions);
		else if ((*stack_b)->data > get_last_element_data(*stack_a))
		{
			pa(stack_a, stack_b, instructions);
			ra(stack_a, instructions);
		}
		else if ((*stack_b)->data > (*stack_a)->next->data)
		{
		ft_printf("\nnext next %d\n", (*stack_a)->next->data);
			if (((*stack_b)->data > (*stack_a)->next->data) && ((*stack_b)->data < (*stack_a)->next->next->data))
			{
				ra(stack_a, instructions);
				ra(stack_a, instructions);
				pa(stack_a, stack_b, instructions);
				rra(stack_a, instructions);
				rra(stack_a, instructions);
			}
			else if (((*stack_b)->data > (*stack_a)->next->next->data) && ((*stack_b)->data < (*stack_a)->next->next->next->data))
			{
				rra(stack_a, instructions);
				pa(stack_a, stack_b, instructions);
				ra(stack_a, instructions);
				ra(stack_a, instructions);
			}
		}
	}
}
