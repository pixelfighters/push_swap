/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:06:46 by kami              #+#    #+#             */
/*   Updated: 2025/03/06 14:07:52 by fschuh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_two(t_stack **stack_ptr)
{
	int		temp;
	t_stack	*first;
	t_stack	*second;

	first = *stack_ptr;
	second = (*stack_ptr)->next;
	if (*stack_ptr == NULL || (*stack_ptr)->next == NULL)
	{
		ft_errhandle("Error msg - not enough elements in stack\n");
	}
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	sa(t_stack **stack_a)
{
	swap_top_two(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap_top_two(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_top_two(stack_a);
	swap_top_two(stack_b);
	ft_printf("ss\n");
}
