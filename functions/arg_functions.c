/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:23:33 by fschuh            #+#    #+#             */
/*   Updated: 2025/04/08 14:28:28 by kami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>


#include <limits.h>
#include <stdlib.h>
#include <errno.h>

// have to check for maximums size ints

// Helper function to remove consecutive spaces
char *remove_consecutive_spaces(const char *str)
{
    int i = 0, j = 0;
    char *result = malloc(strlen(str) + 1);
    if (!result)
        return NULL;

    while (isspace(str[i]))
        i++;

    while (str[i] != '\0')
    {
        if (!isspace(str[i]))
        {
            result[j++] = str[i];
        }
        else if (!isspace(str[i - 1]))
        {
            result[j++] = ' ';
        }
        i++;
    }
    if (j > 0 && isspace(result[j - 1]))
        j--;

    result[j] = '\0';
    return result;
}

int ft_arraylength(int argc, char **argv)
{
    int counter;
    int j;
    char **splitted;

    counter = 0;
    j = 1;
    while (j < argc)
    {
        splitted = ft_split(argv[j], ' ');
        if (splitted)
        {
            int i = 0;
            while (splitted[i] != NULL)
            {
                counter++;
                i++;
            }
            ft_free_split(splitted);
        }
        j++;
    }
    return counter;
}
char **ft_flatten_args(int argc, char **argv)
{
    int i, j, k;
    int arraylength;
    char **splitted;
    char **flattened_array;
    char *cleaned_arg;

    arraylength = ft_arraylength(argc, argv);
    flattened_array = (char **)malloc(sizeof(char *) * (arraylength + 1));
    if (!flattened_array)
        return NULL;

    i = 0;
    j = 1;
    while (j < argc)
    {
        cleaned_arg = remove_consecutive_spaces(argv[j]);
        if (!cleaned_arg)
        {
            for (int x = 0; x < i; x++)
                free(flattened_array[x]);
            free(flattened_array);
            return NULL;
        }
	   splitted = ft_split(cleaned_arg, ' ');
        free(cleaned_arg);

        if (splitted)
        {
            k = 0;
            while (splitted[k] != NULL)
            {
                flattened_array[i] = strdup(splitted[k]);
                if (!flattened_array[i])
                {
                    for (int x = 0; x < i; x++)
                        free(flattened_array[x]);
                    free(flattened_array);
                    ft_free_split(splitted);
                    return NULL;
                }
                i++;
                k++;
            }
            ft_free_split(splitted);
        }
        j++;
    }
    flattened_array[i] = NULL;
    return flattened_array;
}

int is_valid_number(const char *str)
{
    int i = 0;

    if (str[i] == '-')
        i++;
	    while (str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }

    char *endptr;
    long value;
    if (str == NULL || str[0] == '\0')
        return 0;
    if (str[0] == '-' && str[1] == '\0')
        return 0;
    errno = 0;
    // FIX THAT
	value = strtol(str, &endptr, 10);
    if (errno == ERANGE || value < INT_MIN || value > INT_MAX)
        return 0;
    if (*endptr != '\0')
        return 0;
    return (i > 0);
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
            	ft_errhandle("Error");
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
	            ft_errhandle("Error");
			j++;
		}
		i++;
	}
	return (0);
}

char **ft_checkargs(int argc, char **argv)
{
    char **flattened_array;


    flattened_array = ft_flatten_args(argc, argv);

    if (!flattened_array)
        ft_errhandle("Error");

    for (int i = 0; flattened_array[i] != NULL; i++)
    {
        if (!is_valid_number(flattened_array[i]))
        {
            ft_errhandle("Error");
        }
    }

    if (ft_checkdoubles(ft_arraylength(argc, argv), flattened_array))
        ft_errhandle("Error");
    return (flattened_array);
}
