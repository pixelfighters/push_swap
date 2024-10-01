/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:16:14 by kami              #+#    #+#             */
/*   Updated: 2024/09/26 17:39:24 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct stack
{
	int data;
	struct stack* next;
	struct stack* prev;
} stack;

stack *createNode(int data) {
    stack *newNode = (stack *)malloc(sizeof(stack));
    newNode->data = data;

    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void	ft_checkdigit(char *argv)
{
	char error_msg[25]; 
	if(!ft_isdigit(*argv))
	{
		ft_printf("\n");
		ft_print_ascii_art("ARG ERROR", KRED, 1);
		ft_strlcpy(error_msg, "\"", 25);
		error_msg[1] = *argv;
		error_msg[2] = '\0';
		ft_strlcat(error_msg, "\" is not a number\n", 25);
		ft_errhandle(error_msg);
	} 
}

void	ft_checkargs(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 2)
	{
		while(argv[i])
		{
			ft_checkdigit(argv[i]);
			i++;
		}
	}
	else
	{
		ft_print_ascii_art("ARG ERROR", KRED, 1);
		ft_errhandle("Can't sort less than two numbers\n");
	}
}

int main(int argc, char **argv) {
	int i;
	int total_value;

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
	ft_printf("Total value is: %d\n Average is: %d", total_value, (total_value/i));
	ft_printf("\nDoubly linked list (Stack A):\n");
	currentNode = stack_a;
	while (currentNode) {
		ft_printf("%d\n", currentNode->data);
		currentNode = currentNode->next;
	}

	(void)stack_b;

    return 0;
}