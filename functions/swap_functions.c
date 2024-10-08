/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:06:46 by kami              #+#    #+#             */
/*   Updated: 2024/10/08 15:46:41 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

void	swap_top_two(stack **stack_ptr)
{
	int		temp;
	stack	*first;
	stack	*second;

	first = *stack_ptr;
	second = (*stack_ptr)->next;
	if (*stack_ptr == NULL || (*stack_ptr)->next == NULL)
	{
		ft_errhandle("Error msg - not enough elements in stack\n");
	}
	temp = first->data;
	first->data = second->data;
	second->data = temp;
}

void	sa(stack **stack_a)
{
	swap_top_two(stack_a);
	ft_printf("sa\n");
}

void	sb(stack **stack_b)
{
	swap_top_two(stack_b);
	ft_printf("sb\n");	
}

void	ss(stack **stack_a, stack **stack_b)
{
	swap_top_two(stack_a);
	swap_top_two(stack_b);
	ft_printf("ss\n");	
}
