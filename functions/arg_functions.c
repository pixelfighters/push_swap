/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kami <kami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:23:33 by fschuh            #+#    #+#             */
/*   Updated: 2025/04/01 18:37:30 by kami             ###   ########.fr       */
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
    char *result = malloc(strlen(str) + 1); // Allocate memory for the result
    if (!result)
        return NULL;

    // Skip leading spaces
    while (isspace(str[i]))
        i++;

    while (str[i] != '\0')
    {
        // Copy non-space characters
        if (!isspace(str[i]))
        {
            result[j++] = str[i];
        }
        // Copy a single space if the current character is a space
        else if (!isspace(str[i - 1]))
        {
            result[j++] = ' ';
        }
        i++;
    }

    // Remove trailing space if present
    if (j > 0 && isspace(result[j - 1]))
        j--;

    result[j] = '\0'; // Null-terminate the string
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
			// ft_free_split(splitted);
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

    // Calculate the total number of arguments after flattening
    arraylength = ft_arraylength(argc, argv);
    flattened_array = (char **)malloc(sizeof(char *) * (arraylength + 1));
    if (!flattened_array)
        return NULL;

    i = 0;
    j = 1; // Start from argv[1], skipping the program name
    while (j < argc)
    {
        // Preprocess the argument to remove consecutive spaces
        cleaned_arg = remove_consecutive_spaces(argv[j]);
        if (!cleaned_arg)
        {
            // Handle memory allocation failure
            for (int x = 0; x < i; x++)
                free(flattened_array[x]);
            free(flattened_array);
            return NULL;
        }

        // Debug: Print cleaned argument
        // ft_printf("cleaned_arg[%d]: %s\n", j, cleaned_arg);

        splitted = ft_split(cleaned_arg, ' ');
        free(cleaned_arg); // Free the cleaned argument after splitting

        if (splitted)
        {
            k = 0;
            while (splitted[k] != NULL)
            {
                // Copy the string to flattened_array
                flattened_array[i] = strdup(splitted[k]);
                if (!flattened_array[i])
                {
                    // Handle memory allocation failure (free previously allocated memory)
                    for (int x = 0; x < i; x++)
                        free(flattened_array[x]);
                    free(flattened_array);
                    ft_free_split(splitted);
                    return NULL;
                }
                i++;
                k++;
            }
            // Free the splitted array after copying its contents
            ft_free_split(splitted);
        }
        j++;
    }
    flattened_array[i] = NULL; // Null-terminate the array
    return flattened_array;
}

int is_valid_number(const char *str)
{
    int i = 0;

    // Allow a single leading '-' (negative number)
    if (str[i] == '-')
        i++;
	
    // Ensure the rest are digits
    while (str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
            return (0); // Invalid character found
        i++;
    }

    char *endptr;
    long value;

    // Check for an empty string
    if (str == NULL || str[0] == '\0')
        return 0;

    // Check for a single '-' without digits
    if (str[0] == '-' && str[1] == '\0')
        return 0;

    // Reset errno before calling strtol
    errno = 0;

    // Convert the string to a long
    value = strtol(str, &endptr, 10);

    // Check for conversion errors or out-of-range values
    if (errno == ERANGE || value < INT_MIN || value > INT_MAX)
        return 0; // Out of range for int

    // Check if the entire string was converted
    if (*endptr != '\0')
        return 0; // Invalid characters found




    // Return 1 if the string is a valid number
    return (i > 0); // Ensure there's at least one digit
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
	if (argc < 2)
		ft_errhandle("Error");
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
        //    ft_printf("Invalid argument: %s\n", flattened_array[i]); // Debugging print
            ft_errhandle("Error");
        }
    }

    if (ft_checkdoubles(ft_arraylength(argc, argv), flattened_array))
        ft_errhandle("Error");
    return (flattened_array);
}
