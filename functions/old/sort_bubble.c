/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:28:34 by kami              #+#    #+#             */
/*   Updated: 2024/10/09 12:43:29 by fschuh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

void bubble_sort_stack(stack **stack_a, stack **stack_b)
{
    int sorted;
    stack *temp;
	stack_b = stack_a;
    if (!stack_a || !*stack_a) {
        ft_printf("Stack A is empty or not initialized.\n");
        return;
    }

    do {
        sorted = 1;
        temp = *stack_a;
	
        // Traverse the stack and swap adjacent elements if they are in the wrong order
        while (temp && temp->next) {
            if (temp->data > temp->next->data) {
                sa(stack_a);
                ft_printf("-sa\n");
                sorted = 0;
            }
            ra(stack_a);
            ft_printf("-ra\n");
            temp = temp->next;
        }

        // Restore the original order of the stack
        while (temp != *stack_a) {
            rra(stack_a);
            ft_printf("-rra\n");
            temp = temp->prev;
        }
    } while (!sorted);
}