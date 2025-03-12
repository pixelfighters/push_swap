/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:18:38 by fschuh            #+#    #+#             */
/*   Updated: 2025/03/12 14:58:12 by fschuh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_from_ptr, t_stack **stack_to_ptr)
{
	t_stack	*push_value;

	push_value = *stack_from_ptr;
	if (*stack_from_ptr == NULL)
		ft_errhandle("Error msg - nothing in from_stack\n");
	*stack_from_ptr = (*stack_from_ptr)->next;
	if (*stack_from_ptr != NULL)
		(*stack_from_ptr)->prev = NULL;
	push_value->next = *stack_to_ptr;
	if (*stack_to_ptr != NULL)
		(*stack_to_ptr)->prev = push_value;
	*stack_to_ptr = push_value;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
