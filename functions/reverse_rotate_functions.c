/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:06:46 by kami              #+#    #+#             */
/*   Updated: 2024/10/08 12:56:37 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

void	reverse_rotate(stack **stack_ptr)
{
	stack	*last;
	stack	*second_last;

	last = *stack_ptr;
	second_last = NULL;
	if (*stack_ptr == NULL || (*stack_ptr)->next == NULL)
	{
		// checken welche conditions nicht rotieren!!!!!
		ft_errhandle("Error msg - reverse rotate \n");
	}
	// zum letzten element
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	// pointer updaten um stack zu drehen
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack_ptr;
	(*stack_ptr)->prev = last;
	*stack_ptr = last;
}

void	rra(stack **stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(stack **stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr(stack **stack_a, stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
