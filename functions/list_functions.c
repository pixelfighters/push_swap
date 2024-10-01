/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:28:34 by kami              #+#    #+#             */
/*   Updated: 2024/10/01 10:39:45 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

void printStack(stack *stack_a) {
	stack *currentNode = stack_a;
	while (currentNode) {
		printf("%d\n", currentNode->data);
		currentNode = currentNode->next;
	}
}

stack *createNode(int data) {
	stack *newNode = (stack *)malloc(sizeof(stack));
	newNode->data = data;

	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

stack *cloneStack(stack *stack_a)
{
    if (stack_a == NULL) {
        return NULL;
    }

    stack *stack_b = createNode(stack_a->data);
    stack *current_a = stack_a->next;
    stack *current_b = stack_b;

    while (current_a != NULL) {
        stack *newNode = createNode(current_a->data);
        current_b->next = newNode;
        newNode->prev = current_b;
        current_b = newNode;
        current_a = current_a->next;
    }

    return stack_b;
}