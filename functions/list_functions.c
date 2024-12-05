/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:28:34 by kami              #+#    #+#             */
/*   Updated: 2024/10/07 15:42:15 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

void	print_stack(stack *stack_a)
{
	stack	*currentNode;

	currentNode = stack_a;
	while (currentNode)
	{
		printf("%d\n", currentNode->data);
		currentNode = currentNode->next;
	}
}

stack	*create_node(int data)
{
	stack	*newNode;

	newNode = (stack *)malloc(sizeof(stack));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return (newNode);
}

stack	*clone_stack(stack *stack_a)
{
	stack	*stack_b;
	stack	*current_a;
	stack	*current_b;
	stack	*newNode;

	stack_b = create_node(stack_a->data);
	current_a = stack_a->next;
	current_b = stack_b;
	if (stack_a == NULL)
		return (NULL);
	while (current_a != NULL)
	{
		newNode = create_node(current_a->data);
		current_b->next = newNode;
		newNode->prev = current_b;
		current_b = newNode;
		current_a = current_a->next;
	}
	return (stack_b);
}
