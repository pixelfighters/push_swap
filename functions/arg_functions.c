/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:23:33 by fschuh            #+#    #+#             */
/*   Updated: 2025/04/11 15:20:45 by fschuh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*remove_consecutive_spaces(const char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	result = malloc(strlen(str) + 1);
	if (!result)
		return (NULL);
	while (isspace(str[i]))
		i++;
	while (str[i] != '\0')
	{
		if (!isspace(str[i]))
			result[j++] = str[i];
		else if (!isspace(str[i - 1]))
			result[j++] = ' ';
		i++;
	}
	if (j > 0 && isspace(result[j - 1]))
		j--;
	result[j] = '\0';
	return (result);
}

int	update_value_and_check(long long *value, char digit, int sign)
{
	*value = *value * 10 + (digit - '0');
	if (sign == 1 && *value > INT_MAX)
		return (0);
	if (sign == -1 && - *value < INT_MIN)
		return (0);
	return (1);
}

int	is_valid_number(const char *str)
{
	t_numbercheck	check;

	check.i = 0;
	check.sign = 1;
	check.value = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[check.i] == '-' || str[check.i] == '+')
	{
		if (str[check.i] == '-')
			check.sign = -1;
		check.i++;
	}
	if (!ft_isdigit(str[check.i]))
		return (0);
	while (str[check.i])
	{
		if (!ft_isdigit(str[check.i]))
			return (0);
		if (!update_value_and_check(&check.value, str[check.i], check.sign))
			return (0);
		check.i++;
	}
	return (1);
}

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
			if (!is_valid_number(argv[i]))
				return (1);
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_checkargs(int argc, char **argv)
{
	char	**flattened_array;
	int		i;

	if (argv[1][0] == '\0')
		ft_errhandle("Error");
	flattened_array = ft_flatten_args(argc, argv);
	i = 0;
	if (!flattened_array)
		ft_errhandle("Error");
	while (flattened_array[i] != NULL)
	{
		if (!is_valid_number(flattened_array[i]))
		{
			i = 0;
			while (flattened_array[i] != NULL)
			{
				free(flattened_array[i]);
				i++;
			}
			free(flattened_array);
			ft_errhandle("Error");
		}
		i++;
	}
	if (ft_checkdoubles(ft_arraylength(argc, argv), flattened_array))
	{
		i = 0;
		while (flattened_array[i] != NULL)
		{
			free(flattened_array[i]);
			i++;
		}
		free(flattened_array);
		ft_errhandle("Error");
	}
	return (flattened_array);
}
