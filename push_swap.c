/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:28:34 by kami              #+#    #+#             */
/*   Updated: 2025/03/13 14:48:07 by fschuh           ###   ########.fr       */
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
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 0;
	if (!ft_checkargs(argc, argv))
	{
		stack_a = fill_node(argc, argv);
		init_index(stack_a);
		stack_b = NULL;
		ft_count(argc, &stack_a, &stack_b);
		free_list(stack_a);
		free_list(stack_b);
	}
	return (0);
}
