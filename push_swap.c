/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:28:34 by kami              #+#    #+#             */
/*   Updated: 2025/03/12 14:54:54 by fschuh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cc nodes.c -I./libft -L./libft -lft
// cc nodes.c ./functions/list_functions.c ./functions/rotate_functions.c ./functions/sort_simples.c ./functions/swap_functions.c  ./functions/rev_rotate_functions.c ./functions/push_functions.c ./functions/arg_functions.c -I./includes -I./functions -I./libft -L./libft -lft -o nodes 

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
		stack_b = NULL;
		print_list(stack_a);
		ft_count(argc, &stack_a, &stack_b);
		print_list(stack_a);
	}
	return (0);
}
