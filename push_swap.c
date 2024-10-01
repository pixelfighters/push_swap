/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:16:14 by kami              #+#    #+#             */
/*   Updated: 2024/10/01 10:08:52 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "./functions/swap_functions.c"
#include "./functions/check_args.c"
#include "./functions/list_functions.c"
/*#include LINKEDLISTCREATION
#include SWAPFUNCTIONS
#include PUSHFUNCTIONS
#include ROTATEFUNCTIONS
#include REVERSEROTATEFUNCTIONS */

int main(int argc, char **argv) {
	int i;
	int total_value;
	int average;

	i = 1;
	total_value = 0;
	ft_checkargs(argc, argv);
	ft_printf("\nArgs are okay - let's sort 'em\n");

	stack *stack_a = NULL;
	stack *stack_b = NULL;

	stack *currentNode = NULL;

	while (i < argc) 
	{
		int num = ft_atoi(argv[i]);
		total_value += num;
		stack *newNode = createNode(num);
		if (stack_a == NULL) {
			stack_a = newNode;
			currentNode = newNode;
		} else {
			currentNode->next = newNode;
			newNode->prev = currentNode;
			currentNode = newNode;
		}
		i++;
	}
    average = total_value / (argc - 1);
    printf("Total value is: %d\nAverage is: %d\n", total_value, average);
	ft_printf("\nDoubly linked list (Stack A):\n");
	currentNode = stack_a;
	while (currentNode) {
		ft_printf("%d\n", currentNode->data);
		currentNode = currentNode->next;
	}

	(void)stack_b;

	    printf("Stack before swap:\n");
    printStack(stack_a);

    sa(&stack_a);

    printf("Stack after swap:\n");
    printStack(stack_a);

    // Free the allocated memory
    while (stack_a) {
        stack *temp = stack_a;
        stack_a = stack_a->next;
        free(temp);
    }

    return 0;
}