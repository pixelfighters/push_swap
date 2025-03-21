/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:23:33 by fschuh            #+#    #+#             */
/*   Updated: 2025/03/17 15:23:42 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkdoubles(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argc > i)
	{
		j = i + 1;
		while (argc > j)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				ft_printf("Error\n");
				ft_printf("%s is a duplicate of %s\n", argv[i], argv[j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_checkargs(int argc, char **argv)
{
	int	i;
	int	number;

	i = 1;
	while (argc > i)
	{
		number = (ft_atoi(argv[i]));
		if (!number && argv[i][0] != '0')
		{
			ft_printf("Error\n");
			ft_printf("Argument %s is not a number\n", argv[i]);
			return (1);
		}
		i++;
	}
	if (!ft_checkdoubles(argc, argv))
		return (0);
	return (1);
}
