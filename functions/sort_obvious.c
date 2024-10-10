/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_obvious.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:28:34 by kami              #+#    #+#             */
/*   Updated: 2024/10/10 12:43:32 by fschuh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

void	two_sort_stack(stack **stack_a)
{
	ra(stack_a);
}

void	three_sort_stack(stack **stack_a)
{
	while(!is_sorted(*stack_a))
	{
		if ((*stack_a)->data < (*stack_a)->next->data)
			sa(stack_a);
		else if ((*stack_a)->next->data < (*stack_a)->data)
			ra(stack_a);
		else
			rra(stack_a);
	}

}

void five_sort_stack(stack **stack_a, stack **stack_b)
{
    int i = 0;
    while (get_stack_size(*stack_a) > 3)
    {
        pb(stack_a, stack_b); 
    }
    three_sort_stack(stack_a);
	two_sort_stack(stack_b);
	while(!is_sorted(*stack_a) || get_stack_size(*stack_a) != 5)
	
	{
		if ((*stack_b)->data < (*stack_a)->data)
			pa(stack_a, stack_b);
		else
		{
			rra(stack_a);
			pa(stack_a, stack_b);
			ra(stack_a);
			ra(stack_a);
			if (!is_sorted(*stack_a))
				ft_printf("a is sorted");
				
		}
	}
i++;
/*     while (get_stack_size(*stack_a))
    {
        if ((*stack_b)->data < (*stack_a)->data)
        {
            pa(stack_a, stack_b); 
        }
        else
        {
            ra(stack_a);
			pa(stack_a, stack_b);
        }
		i++;
    } */
	ft_printf("\nstack a\n");
	print_stack(*stack_a);
	ft_printf("\nstack b\n");
	print_stack(*stack_b);

    ft_printf("\nFinal sorted stack a:\n");
    print_stack(*stack_a);
}
