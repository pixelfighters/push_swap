/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:21:23 by kami              #+#    #+#             */
/*   Updated: 2024/10/01 09:42:09 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

// Define the stack node structure
typedef struct stack {
    int data;
    struct stack *next;
    struct stack *prev;
} stack;

// Function prototypes
void sa(stack **stack_a);
void sb(stack **stack_b);
void printStack(stack *stack_a);
stack *createNode(int data);

#endif 