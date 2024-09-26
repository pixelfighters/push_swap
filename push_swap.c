/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:16:14 by kami              #+#    #+#             */
/*   Updated: 2024/09/26 16:10:03 by kami             ###   ########.fr       */
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

int main(int argc, char **argv)
{
    ft_checkargs(argc, argv);
    ft_printf("\nArgs are okay - let's sort 'em\n");

    stack *firstNode = NULL;
    stack *currentNode = NULL;

    for (int i = 1; i < argc; i++) {
        int num = ft_atoi(argv[i]); 

        stack *newNode = createNode(num);
        if (firstNode == NULL) {
            firstNode = newNode;
            currentNode = newNode;
        } else {
            currentNode->next = newNode;
            newNode->prev = currentNode;
            currentNode = newNode;
        }
    }

    ft_printf("\nDoubly linked list:\n");
    currentNode = firstNode;
    while (currentNode) {
        ft_printf("%d\n", currentNode->data);
        currentNode = currentNode->next;
    }

    return 0;
}