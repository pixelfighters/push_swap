/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:28:34 by kami              #+#    #+#             */
/*   Updated: 2025/03/17 15:40:13 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  cc push_swap.c ./functions/list_functions.c 
./functions/rotate_functions.c ./functions/sort_simples.c 
./functions/swap_functions.c
  ./functions/rev_rotate_functions.c ./functions/push_functions.c 
  ./functions/arg_functions.c
-I./includes -I./functions -I./libft -L./libft -lft -o push_swap  */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!ft_checkargs(argc, argv))
	{
		stack_a = fill_node(argc, argv);
		init_index(stack_a);
		print_list(stack_a);
		stack_b = NULL;
		ft_count(argc, &stack_a, &stack_b);
		print_list(stack_a);
		free_list(stack_a);
		free_list(stack_b);
	}
	return (0);
}
