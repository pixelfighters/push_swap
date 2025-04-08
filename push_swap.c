/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:28:34 by kami              #+#    #+#             */
/*   Updated: 2025/04/08 14:28:51 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  cc push_swap.c ./functions/list_functions.c ./functions/rotate_functions.c ./functions/sort_simples.c ./functions/swap_functions.c   ./functions/rev_rotate_functions.c ./functions/push_functions.c    ./functions/arg_functions.c -I./includes -I./functions -I./libft -L./libft -lft -o push_swap  */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int i;
    char **flattened_array;

    if (argc < 2)
        ft_errhandle("Error");

    flattened_array = ft_checkargs(argc, argv);
stack_a = fill_node(ft_arraylength(argc, argv), flattened_array);
    init_index(stack_a);

    stack_b = NULL;
    ft_count(ft_arraylength(argc, argv), &stack_a, &stack_b);
    free_list(stack_a);
    free_list(stack_b);
    i = 0;
    while (flattened_array[i] != NULL)
    {
        free(flattened_array[i]);
        i++;
    }
    free(flattened_array);

    return (0);
}
