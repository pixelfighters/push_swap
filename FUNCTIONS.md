# Push_swap Functions Documentation

## Overview

This document provides detailed documentation for all functions in the push_swap project, organized by their purpose and file location.

## Table of Contents

- [Data Structures](#data-structures)
- [Main Program](#main-program)
- [Argument Processing](#argument-processing)
- [Stack Operations](#stack-operations)
- [Sorting Algorithms](#sorting-algorithms)
- [Utility Functions](#utility-functions)
- [Memory Management](#memory-management)

## Data Structures

### `t_stack` (Stack Node)
```c
typedef struct s_node
{
    int             value;   // The integer value
    int             index;   // Relative position index (0 = smallest)
    struct s_node   *next;   // Pointer to next node
    struct s_node   *prev;   // Pointer to previous node
} t_stack;
```

### `t_numbercheck` (Number Validation)
```c
typedef struct s_numbercheck
{
    int         i;      // Iterator index
    int         sign;   // Sign of the number (1 or -1)
    long long   value;  // Temporary value for overflow checking
} t_numbercheck;
```

### `t_arraydata` (Array Processing)
```c
typedef struct s_arraydata
{
    int     i;                  // Current index
    int     j;                  // Loop counter
    int     k;                  // Inner loop counter
    int     x;                  // Utility counter
    int     arrlen;             // Total array length
    char    **splitted;         // Split result array
    char    **flattened_array;  // Final flattened array
    char    *cleaned_arg;       // Cleaned argument string
} t_arraydata;
```

## Main Program

### `main.c`

#### `int main(int argc, char **argv)`
**Purpose**: Entry point of the push_swap program.

**Parameters**:
- `argc`: Number of command-line arguments
- `argv`: Array of command-line argument strings

**Return**: 0 on success, exits with failure on error

**Flow**:
1. Check if no arguments provided → return 0
2. Validate and flatten arguments → `ft_checkargs()`
3. Create initial stack → `fill_node()`
4. Initialize indices → `init_index()`
5. Sort the stack → `ft_count()`
6. Clean up memory → `free_list()`

**Example**:
```c
// Usage: ./push_swap 3 2 1
int main(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    
    char **flattened_array = ft_checkargs(argc, argv);
    t_stack *stack_a = fill_node(ft_arraylength(argc, argv), flattened_array);
    // ... rest of the function
}
```

## Argument Processing

### `arg_functions.c`

#### `char **ft_checkargs(int argc, char **argv)`
**Purpose**: Validates and processes command-line arguments.

**Parameters**:
- `argc`: Number of arguments
- `argv`: Array of argument strings

**Return**: Flattened array of valid number strings

**Validation Steps**:
1. Check for empty first argument
2. Flatten arguments with spaces
3. Validate each number string
4. Check for duplicates
5. Return validated array

**Error Handling**:
- Empty arguments → Error
- Invalid numbers → Error
- Duplicates → Error
- Memory allocation failure → Error

#### `int is_valid_number(const char *str)`
**Purpose**: Validates if a string represents a valid integer.

**Parameters**:
- `str`: String to validate

**Return**: 1 if valid, 0 if invalid

**Validation Rules**:
- Must not be NULL or empty
- Can start with '+' or '-'
- Must contain only digits after sign
- Must not exceed INT_MAX or INT_MIN

**Example**:
```c
is_valid_number("42")      // Returns 1
is_valid_number("-42")     // Returns 1
is_valid_number("42a")     // Returns 0
is_valid_number("++42")    // Returns 0
```

#### `int ft_checkdoubles(int argc, char **argv)`
**Purpose**: Checks for duplicate numbers in the argument array.

**Parameters**:
- `argc`: Number of elements in array
- `argv`: Array of number strings

**Return**: 1 if duplicates found, 0 if no duplicates

**Algorithm**: O(n²) comparison of all pairs

#### `char *remove_consecutive_spaces(const char *str)`
**Purpose**: Removes consecutive spaces and trims whitespace.

**Parameters**:
- `str`: Input string

**Return**: Cleaned string with single spaces

**Processing**:
1. Skip leading whitespace
2. Copy non-space characters
3. Replace consecutive spaces with single space
4. Remove trailing whitespace

### `flatten_args.c`

#### `char **ft_flatten_args(int argc, char **argv)`
**Purpose**: Converts multiple arguments into a single flattened array.

**Parameters**:
- `argc`: Number of arguments
- `argv`: Array of argument strings

**Return**: NULL-terminated array of individual number strings

**Process**:
1. Calculate total length needed
2. Allocate result array
3. Process each argument:
   - Clean consecutive spaces
   - Split on spaces
   - Add to result array
4. Return flattened array

**Example**:
```c
// Input: ["./push_swap", "1 2", "3", "4 5"]
// Output: ["1", "2", "3", "4", "5", NULL]
```

#### `int ft_arraylength(int argc, char **argv)`
**Purpose**: Calculates total number of integers across all arguments.

**Parameters**:
- `argc`: Number of arguments
- `argv`: Array of argument strings

**Return**: Total count of numbers

**Algorithm**: Split each argument and count elements

## Stack Operations

### `list_functions.c`

#### `t_stack *fill_node(int argc, char **argv)`
**Purpose**: Creates the initial stack from validated arguments.

**Parameters**:
- `argc`: Number of elements
- `argv`: Array of number strings

**Return**: Pointer to head of doubly-linked list

**Process**:
1. Allocate memory for each node
2. Convert string to integer
3. Link nodes with next/prev pointers
4. Return head pointer

#### `void free_list(t_stack *stack)`
**Purpose**: Frees all memory allocated for a stack.

**Parameters**:
- `stack`: Pointer to stack head

**Return**: void

**Process**: Traverse and free each node

#### `int stack_size(t_stack *stack_a)`
**Purpose**: Returns the number of elements in a stack.

**Parameters**:
- `stack_a`: Pointer to stack head

**Return**: Number of elements

**Algorithm**: Simple traversal counter

#### `t_stack *ft_last_item(t_stack *stack)`
**Purpose**: Returns pointer to the last element in a stack.

**Parameters**:
- `stack`: Pointer to stack head

**Return**: Pointer to last node

**Algorithm**: Traverse until next is NULL

### `swap_functions.c`

#### `void sa(t_stack **stack_a)`
**Purpose**: Swaps the first two elements of stack a.

**Parameters**:
- `stack_a`: Pointer to stack a head pointer

**Return**: void

**Action**: Exchanges values of first two nodes, prints "sa"

#### `void sb(t_stack **stack_b)`
**Purpose**: Swaps the first two elements of stack b.

**Parameters**:
- `stack_b`: Pointer to stack b head pointer

**Return**: void

**Action**: Exchanges values of first two nodes, prints "sb"

#### `void ss(t_stack **stack_a, t_stack **stack_b)`
**Purpose**: Performs sa and sb simultaneously.

**Parameters**:
- `stack_a`: Pointer to stack a head pointer
- `stack_b`: Pointer to stack b head pointer

**Return**: void

**Action**: Swaps top two elements of both stacks, prints "ss"

### `push_functions.c`

#### `void pa(t_stack **stack_a, t_stack **stack_b)`
**Purpose**: Pushes top element from stack b to stack a.

**Parameters**:
- `stack_a`: Pointer to stack a head pointer
- `stack_b`: Pointer to stack b head pointer

**Return**: void

**Action**: Moves top element from b to top of a, prints "pa"

#### `void pb(t_stack **stack_a, t_stack **stack_b)`
**Purpose**: Pushes top element from stack a to stack b.

**Parameters**:
- `stack_a`: Pointer to stack a head pointer
- `stack_b`: Pointer to stack b head pointer

**Return**: void

**Action**: Moves top element from a to top of b, prints "pb"

### `rotate_functions.c`

#### `void ra(t_stack **stack_a)`
**Purpose**: Rotates stack a up (top becomes bottom).

**Parameters**:
- `stack_a`: Pointer to stack a head pointer

**Return**: void

**Action**: Moves top element to bottom, prints "ra"

#### `void rb(t_stack **stack_b)`
**Purpose**: Rotates stack b up (top becomes bottom).

**Parameters**:
- `stack_b`: Pointer to stack b head pointer

**Return**: void

**Action**: Moves top element to bottom, prints "rb"

#### `void rr(t_stack **stack_a, t_stack **stack_b)`
**Purpose**: Performs ra and rb simultaneously.

**Parameters**:
- `stack_a`: Pointer to stack a head pointer
- `stack_b`: Pointer to stack b head pointer

**Return**: void

**Action**: Rotates both stacks up, prints "rr"

### `rev_rotate_functions.c`

#### `void rra(t_stack **stack_a)`
**Purpose**: Rotates stack a down (bottom becomes top).

**Parameters**:
- `stack_a`: Pointer to stack a head pointer

**Return**: void

**Action**: Moves bottom element to top, prints "rra"

#### `void rrb(t_stack **stack_b)`
**Purpose**: Rotates stack b down (bottom becomes top).

**Parameters**:
- `stack_b`: Pointer to stack b head pointer

**Return**: void

**Action**: Moves bottom element to top, prints "rrb"

#### `void rrr(t_stack **stack_a, t_stack **stack_b)`
**Purpose**: Performs rra and rrb simultaneously.

**Parameters**:
- `stack_a`: Pointer to stack a head pointer
- `stack_b`: Pointer to stack b head pointer

**Return**: void

**Action**: Rotates both stacks down, prints "rrr"

## Sorting Algorithms

### `sort_algorithm.c`

#### `void init_index(t_stack *stack)`
**Purpose**: Assigns index values based on relative order.

**Parameters**:
- `stack`: Pointer to stack head

**Return**: void

**Algorithm**: For each element, count how many elements are smaller

**Example**:
```c
// Values:  [5, 2, 8, 1, 9]
// Indices: [2, 1, 3, 0, 4]
```

#### `int read_bits(t_stack **stack)`
**Purpose**: Calculates number of bits needed for radix sort.

**Parameters**:
- `stack`: Pointer to stack head pointer

**Return**: Number of bits in maximum index

**Algorithm**: Find max index, count bits needed

#### `void sort_radix(t_stack **stack_a, t_stack **stack_b)`
**Purpose**: Implements radix sort algorithm.

**Parameters**:
- `stack_a`: Pointer to stack a head pointer
- `stack_b`: Pointer to stack b head pointer

**Return**: void

**Algorithm**: Process each bit position, sort elements by bit value

### `sort_simples.c`

#### `int is_sorted(t_stack *stack_a)`
**Purpose**: Checks if stack is sorted in ascending order.

**Parameters**:
- `stack_a`: Pointer to stack head

**Return**: 1 if sorted, 0 if not sorted

**Algorithm**: Compare adjacent elements

#### `void sort_three(t_stack **stack_a)`
**Purpose**: Optimized sorting for exactly 3 elements.

**Parameters**:
- `stack_a`: Pointer to stack a head pointer

**Return**: void

**Algorithm**: Hardcoded cases for all 6 permutations

#### `void sort_four(t_stack **stack_a, t_stack **stack_b)`
**Purpose**: Optimized sorting for exactly 4 elements.

**Parameters**:
- `stack_a`: Pointer to stack a head pointer
- `stack_b`: Pointer to stack b head pointer

**Return**: void

**Algorithm**: Move one element to b, sort 3, reinsert

#### `void sort_five(t_stack **stack_a, t_stack **stack_b)`
**Purpose**: Optimized sorting for exactly 5 elements.

**Parameters**:
- `stack_a`: Pointer to stack a head pointer
- `stack_b`: Pointer to stack b head pointer

**Return**: void

**Algorithm**: Move two smallest to b, sort 3, reinsert

#### `int ft_count(int argc, t_stack **stack_a, t_stack **stack_b)`
**Purpose**: Main sorting dispatcher.

**Parameters**:
- `argc`: Number of elements
- `stack_a`: Pointer to stack a head pointer
- `stack_b`: Pointer to stack b head pointer

**Return**: 0 on success

**Algorithm**: Choose appropriate sorting method based on size

### `sort_functions.c`

#### `int find_smallest(t_stack *stack)`
**Purpose**: Finds the smallest value in a stack.

**Parameters**:
- `stack`: Pointer to stack head

**Return**: Smallest value

**Algorithm**: Linear search

#### `int find_biggest(t_stack *stack)`
**Purpose**: Finds the biggest value in a stack.

**Parameters**:
- `stack`: Pointer to stack head

**Return**: Biggest value

**Algorithm**: Linear search

#### `void push_to_top(t_stack **stack, int value)`
**Purpose**: Moves a specific value to the top of a stack.

**Parameters**:
- `stack`: Pointer to stack head pointer
- `value`: Value to move to top

**Return**: void

**Algorithm**: Choose most efficient rotation direction

#### `int find_position(t_stack *stack, int value)`
**Purpose**: Finds the position of a value in a stack.

**Parameters**:
- `stack`: Pointer to stack head
- `value`: Value to find

**Return**: 0-based position from top

**Algorithm**: Linear search with position counter

#### `void push_to_correct_position(t_stack **stack_a, int value)`
**Purpose**: Positions stack a to insert value in correct sorted position.

**Parameters**:
- `stack_a`: Pointer to stack a head pointer
- `value`: Value to be inserted

**Return**: void

**Algorithm**: Find insertion point, rotate to position

## Utility Functions

### Error Handling

#### `void ft_errhandle(char *error_msg)` (libft)
**Purpose**: Prints error message to stderr and exits.

**Parameters**:
- `error_msg`: Error message to print

**Return**: Does not return (exits program)

**Action**: Writes message to stderr, exits with failure

### Memory Management

#### `void ft_free_split(char **split)` (libft)
**Purpose**: Frees memory allocated for split string array.

**Parameters**:
- `split`: Array of strings to free

**Return**: void

**Process**: Free each string, then free array pointer

### String Utilities

#### `char **ft_split(char const *s, char c)` (libft)
**Purpose**: Splits string into array of substrings.

**Parameters**:
- `s`: String to split
- `c`: Delimiter character

**Return**: Array of substrings

**Algorithm**: Find delimiters, allocate substrings

#### `int ft_atoi(const char *str)` (libft)
**Purpose**: Converts string to integer.

**Parameters**:
- `str`: String to convert

**Return**: Integer value

**Algorithm**: Parse sign, convert digits

## Function Call Flow

```
main()
├── ft_checkargs()
│   ├── ft_flatten_args()
│   │   ├── ft_arraylength()
│   │   ├── remove_consecutive_spaces()
│   │   └── ft_split()
│   ├── is_valid_number()
│   └── ft_checkdoubles()
├── fill_node()
├── init_index()
├── ft_count()
│   ├── sort_three()
│   ├── sort_four()
│   ├── sort_five()
│   └── sort_radix()
│       ├── read_bits()
│       └── stack operations (pa, pb, ra, rb, etc.)
└── free_list()
```

## Error Handling Strategy

1. **Input Validation**: Check arguments before processing
2. **Memory Management**: Free allocated memory on errors
3. **Graceful Exit**: Use ft_errhandle() for consistent error reporting
4. **Resource Cleanup**: Always free stacks and arrays before exit

This comprehensive function documentation provides developers with all the information needed to understand, maintain, and extend the push_swap project.