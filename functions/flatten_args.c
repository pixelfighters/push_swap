/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flatten_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuh <fschuh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:29:16 by fschuh            #+#    #+#             */
/*   Updated: 2025/04/11 15:21:13 by fschuh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arraylength(int argc, char **argv)
{
	int		counter;
	int		j;
	int		i;
	char	**splitted;

	counter = 0;
	j = 1;
	while (j < argc)
	{
		splitted = ft_split(argv[j], ' ');
		if (splitted)
		{
			i = 0;
			while (splitted[i] != NULL)
			{
				counter++;
				i++;
			}
			ft_free_split(splitted);
		}
		j++;
	}
	return (counter);
}

void	free_flattened_array(t_arraydata *data)
{
	data->x = 0;
	while (data->x < data->i)
	{
		free(data->flattened_array[data->x]);
		data->x++;
	}
	free(data->flattened_array);
}

void	free_flattened_and_splitted(t_arraydata *data)
{
	data->x = 0;
	while (data->x < data->i)
	{
		free(data->flattened_array[data->x]);
		data->x++;
	}
	free(data->flattened_array);
	ft_free_split(data->splitted);
}

int	add_splitted_to_flattened(t_arraydata *data)
{
	data->k = 0;
	while (data->splitted[data->k] != NULL)
	{
		data->flattened_array[data->i] = strdup(data->splitted[data->k]);
		if (!data->flattened_array[data->i])
		{
			free_flattened_and_splitted(data);
			return (0);
		}
		data->i++;
		data->k++;
	}
	ft_free_split(data->splitted);
	return (1);
}

char	**ft_flatten_args(int argc, char **argv)
{
	t_arraydata	data;

	data.arrlen = ft_arraylength(argc, argv);
	data.flattened_array = (char **)malloc(sizeof(char *) * (data.arrlen + 1));
	if (!data.flattened_array)
		return (NULL);
	data.i = 0;
	data.j = 1;
	while (data.j < argc)
	{
		data.cleaned_arg = (char *)remove_consecutive_spaces(argv[data.j]);
		if (!data.cleaned_arg)
		{
			free_flattened_array(&data);
			return (NULL);
		}
		if (ft_strlen(data.cleaned_arg) == 0)
		{
			free(data.cleaned_arg);
			free(data.flattened_array);
			ft_errhandle("Error");
		}
		data.splitted = ft_split(data.cleaned_arg, ' ');
		free(data.cleaned_arg);
		if (data.splitted)
			if (!add_splitted_to_flattened(&data))
				return (NULL);
		data.j++;
	}
	data.flattened_array[data.i] = NULL;
	return (data.flattened_array);
}
