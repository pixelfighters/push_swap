/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:16:55 by kami              #+#    #+#             */
/*   Updated: 2024/10/01 10:43:08 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

void sa(stack **stack_a) 
{
	int temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		return;
	}

	stack *first = *stack_a;
	stack *second = (*stack_a)->next;

	temp = first->data;
	first->data = second->data;
	second->data = temp;
}

void sb(stack **stack_b) 
{
	int temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
	{
		return;
	}

	stack *first = *stack_b;
	stack *second = (*stack_b)->next;

	temp = first->data;
	first->data = second->data;
	second->data = temp;
}

void ss(stack **stack_b, stack **stack_a)
{
	sa(stack_a);
	sb(stack_b);
}