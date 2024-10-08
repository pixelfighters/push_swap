/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:16:14 by kami              #+#    #+#             */
/*   Updated: 2024/10/08 13:10:57 by kami             ###   ########.fr       */
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

int get_max_bits(stack *stack_a) {
    int max = 0;
    while (stack_a) {
        if (stack_a->data > max) {
            max = stack_a->data;
        }
        stack_a = stack_a->next;
    }
    int bits = 0;
    while ((max >> bits) != 0) {
        bits++;
    }
    return bits;
}

// Radix Sort implementation using stack operations
void sort_stack(stack **stack_a, stack **stack_b) 
{

	    int max_bits = get_max_bits(*stack_a);
    int size = 0;
    stack *temp = *stack_a;

    // Get the size of the stack
    while (temp) {
        size++;
        temp = temp->next;
    }

    for (int i = 0; i < max_bits; i++) {
        for (int j = 0; j < size; j++) {
            if ((((*stack_a)->data >> i) & 1) == 1) {
                ra(stack_a);
				ft_printf("ra\n");
            } else {
                pb(stack_a, stack_b);
				ft_printf("pb\n");
            }
        }
        while (*stack_b) {
            pa(stack_a, stack_b);
			ft_printf("pa\n");
        }
    }
	// ft_printf("Counter: %d\n", counter);
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
        sort_stack(&stack_a, &stack_b);
    }

 //   printf("\nStack A after:\n");
   // print_stack(stack_a);	
	// Free memory
	while (stack_a)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
	}
	return (0);
}
