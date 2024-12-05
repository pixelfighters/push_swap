/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:06:46 by kami              #+#    #+#             */
/*   Updated: 2024/12/04 16:02:59 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

void add_instruction(instruction **instructions, const char *command)
{
	instruction *new_instruction = malloc(sizeof(instruction));
	if (!new_instruction)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	new_instruction->command = strdup(command);
	new_instruction->next = NULL;

	if (*instructions == NULL)
	{
		*instructions = new_instruction;
	} else
	{
		instruction *temp = *instructions;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = new_instruction;
	}
}

void execute_instructions(instruction *instructions, stack **stack_a, stack **stack_b)
{
	while (instructions)
	{
		if (strcmp(instructions->command, "pb") == 0)
			pb(stack_a, stack_b, instructions);
		else if (strcmp(instructions->command, "pa") == 0)
			pa(stack_a, stack_b, instructions);
		else if (strcmp(instructions->command, "ra") == 0)
			ra(stack_a, instructions);
		else if (strcmp(instructions->command, "rb") == 0)
			rb(stack_b, instructions);
		else if (strcmp(instructions->command, "rr") == 0)
			rr(stack_a, stack_b, instructions);
		else if (strcmp(instructions->command, "rra") == 0)
			rra(stack_a, instructions);
		else if (strcmp(instructions->command, "rrb") == 0)
			rrb(stack_b, instructions);
		else if (strcmp(instructions->command, "rrr") == 0)
			rrr(stack_a, stack_b, instructions);
		else if (strcmp(instructions->command, "sa") == 0)
			sa(stack_a, instructions);
		else if (strcmp(instructions->command, "sb") == 0)
			sb(stack_b, instructions);
		else if (strcmp(instructions->command, "ss") == 0)
			ss(stack_a, stack_b, instructions);
		instructions = instructions->next;
	}
}