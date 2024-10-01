/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:21:23 by kami              #+#    #+#             */
/*   Updated: 2024/10/01 10:41:42 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack *next;
    struct stack *prev;
} stack;

void	ft_checkdigit(char *argv);
void	ft_checkargs(int argc, char **argv);
void	sa(stack **stack_a);
void	sb(stack **stack_b);
void	ss(stack **stack_a, stack **stack_b);
void	printStack(stack *stack_a);
stack	*createNode(int data);
stack *cloneStack(stack *stack_a);
/*
LINKEDLISTCREATION
SWAPFUNCTIONS
PUSHFUNCTIONS
ROTATEFUNCTIONS
REVERSEROTATEFUNCTIONS */

#endif 