/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:16:14 by kami              #+#    #+#             */
/*   Updated: 2024/10/08 16:14:08 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdbool.h>

bool is_sorted(stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
		{
			return false;
		}
		stack_a = stack_a->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	int		i;
	int		total_value;
	// int		average;
	int		num;
	stack	*stack_a;
	stack	*stack_b;
	stack	*currentNode;
	stack	*newNode;
	stack	*temp;

	stack_a = NULL;
	stack_b = NULL;
	currentNode = NULL;
	i = 1;
	total_value = 0;
	ft_checkargs(argc, argv);
	// ft_printf("\nArgs are okay - let's sort 'em\n");
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		total_value += num;
		newNode = create_node(num);
		if (stack_a == NULL)
		{
			stack_a = newNode;
			currentNode = newNode;
		}
		else
		{
			currentNode->next = newNode;
			newNode->prev = currentNode;
			currentNode = newNode;
		}
		i++;
	}
	// average = total_value / (argc - 1);
	// ft_printf("Total value is: %d\nAverage is: %d\n\n", total_value, average);
	currentNode = stack_a;
	while (currentNode)
	{
		// ft_printf("%d\n", currentNode->data);
		currentNode = currentNode->next;
	}
/* 	stack_b = clone_stack(stack_a);
	ft_printf("Stack A before:\n");
	print_stack(stack_a);
	ft_printf("\nStack B before:\n");
	print_stack(stack_b);
	rrr(&stack_a, &stack_b);
	ft_printf("\nStack A after:\n");
	print_stack(stack_a);
	ft_printf("\nStack B after:\n");
	print_stack(stack_b); */
    // printf("Stack A before:\n");
   // print_stack(stack_a);
    // printf("\nStack B before:\n");
  //  print_stack(stack_b);

    // Sort stack_a
    if (is_sorted(stack_a)) {
        // ft_printf("\nStack is already sorted.\n");
    } else {
        // ft_printf("\nStack is not sorted. Sorting...\n");
       // radix_sort_stack(&stack_a, &stack_b);
	   counting_sort_stack(&stack_a, &stack_b);
	}
 //   printf("\nStack A after:\n");
   print_stack(stack_a);	
	// Free memory
	while (stack_a)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
	}
	return (0);
}
