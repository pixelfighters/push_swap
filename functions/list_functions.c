/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:28:34 by kami              #+#    #+#             */
/*   Updated: 2024/10/01 10:02:17 by kami             ###   ########.fr       */
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