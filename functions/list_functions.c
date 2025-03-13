/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:18:38 by fschuh            #+#    #+#             */
/*   Updated: 2025/03/13 14:45:37 by fschuh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int	stack_size(t_stack *stack_a)
{
	int	size;

	size = 0;
	while (stack_a != NULL)
	{
		size++;
		stack_a = stack_a->next;
	}
	return (size);
}

void	print_list(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp != NULL)
	{
		ft_printf("%d ", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
}

t_stack	*fill_node(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*temp;
	t_stack	*new_node;
	int		i;

	i = 1;
	stack_a = NULL;
	temp = NULL;
	new_node = NULL;
	while (argc > i)
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->value = atoi(argv[i]);
		new_node->next = NULL;
		new_node->prev = temp;
		if (temp)
			temp->next = new_node;
		else
			stack_a = new_node;
		temp = new_node;
		i++;
	}
	return (stack_a);
}

t_stack	*ft_last_item(t_stack *stack)
{
	while (stack && stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}
