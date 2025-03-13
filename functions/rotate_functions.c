/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:06:46 by kami              #+#    #+#             */
/*   Updated: 2025/03/13 14:43:40 by fschuh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack_ptr)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack_ptr != NULL && (*stack_ptr)->next != NULL)
	{
		first = *stack_ptr;
		last = *stack_ptr;
		while (last->next != NULL)
			last = last->next;
		*stack_ptr = first->next;
		(*stack_ptr)->prev = NULL;
		first->next = NULL;
		first->prev = last;
		last->next = first;
	}
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
