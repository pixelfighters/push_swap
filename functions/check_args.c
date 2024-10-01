/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:27:14 by kami              #+#    #+#             */
/*   Updated: 2024/10/01 10:36:04 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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

// MAX SIZE OF INTS????