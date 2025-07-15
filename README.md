# Push_swap

A 42 School project that implements an efficient sorting algorithm using two stacks and a limited set of operations.

## Overview

The push_swap program sorts a list of integers using two stacks (a and b) and a predefined set of operations. The goal is to sort the numbers in stack a in ascending order with the minimum number of operations possible.

## Table of Contents

- [Project Structure](#project-structure)
- [Compilation](#compilation)
- [Usage](#usage)
- [Algorithm](#algorithm)
- [Stack Operations](#stack-operations)
- [Functions Documentation](#functions-documentation)
- [Testing](#testing)
- [Performance](#performance)

## Project Structure

```
push_swap/
├── Makefile
├── push_swap.c          # Main program file
├── includes/
│   └── push_swap.h      # Header file with function prototypes
├── functions/
│   ├── arg_functions.c      # Argument validation and parsing
│   ├── flatten_args.c       # Argument flattening utilities
│   ├── list_functions.c     # Stack manipulation and utilities
│   ├── push_functions.c     # Push operations (pa, pb)
│   ├── rotate_functions.c   # Rotate operations (ra, rb, rr)
│   ├── rev_rotate_functions.c  # Reverse rotate operations (rra, rrb, rrr)
│   ├── swap_functions.c     # Swap operations (sa, sb, ss)
│   ├── sort_algorithm.c     # Radix sort implementation
│   ├── sort_functions.c     # Utility functions for sorting
│   └── sort_simples.c       # Optimized sorting for small arrays
└── libft/               # Custom C library
    ├── Makefile
    ├── libft.h
    └── *.c files
```

## Compilation

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and binary
make re     # Full recompilation
```

## Usage

```bash
./push_swap [list of integers]
```

### Examples

```bash
# Sort a simple list
./push_swap 2 1 3 6 5 8

# Sort with negative numbers
./push_swap -1 5 -3 2 0

# Sort with a single argument containing spaces
./push_swap "3 2 1 4"

# Error cases
./push_swap 1 2 3 2      # Duplicate numbers
./push_swap 1 2 abc      # Invalid characters
./push_swap 2147483648   # Integer overflow
```

### Output

- **Success**: Sequence of operations separated by newlines
- **Error**: "Error" printed to stderr
- **Already sorted**: No output (empty)

## Algorithm

The program uses different sorting strategies based on the input size:

### Small Arrays (≤ 5 elements)
- **1-2 elements**: Already sorted or simple swap
- **3 elements**: Optimized hardcoded cases
- **4-5 elements**: Move smallest elements to stack b, sort remaining, then reconstruct

### Large Arrays (> 5 elements)
- **Radix Sort**: Efficient O(n*k) algorithm where k is the number of bits
- Uses binary representation of indexed values
- Sorts bit by bit from least significant to most significant

## Stack Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first 2 elements of stack a |
| `sb` | Swap first 2 elements of stack b |
| `ss` | sa and sb simultaneously |
| `pa` | Push top element from b to a |
| `pb` | Push top element from a to b |
| `ra` | Rotate stack a (top becomes bottom) |
| `rb` | Rotate stack b (top becomes bottom) |
| `rr` | ra and rb simultaneously |
| `rra` | Reverse rotate stack a (bottom becomes top) |
| `rrb` | Reverse rotate stack b (bottom becomes top) |
| `rrr` | rra and rrb simultaneously |

## Functions Documentation

### Main Program (`push_swap.c`)

#### `main(int argc, char **argv)`
- Entry point of the program
- Validates arguments and initializes stacks
- Calls appropriate sorting function
- Handles memory cleanup

### Argument Processing (`arg_functions.c`)

#### `char **ft_checkargs(int argc, char **argv)`
- Validates and processes command line arguments
- Checks for duplicates, invalid characters, and overflow
- Returns flattened array of valid integers

#### `int is_valid_number(const char *str)`
- Validates if a string represents a valid integer
- Handles signs, overflow, and invalid characters

#### `int ft_checkdoubles(int argc, char **argv)`
- Checks for duplicate numbers in the argument list
- Returns 1 if duplicates found, 0 otherwise

#### `char *remove_consecutive_spaces(const char *str)`
- Removes consecutive spaces from input string
- Trims leading and trailing whitespace

### Argument Flattening (`flatten_args.c`)

#### `char **ft_flatten_args(int argc, char **argv)`
- Converts multiple arguments into a single flattened array
- Handles arguments with spaces (e.g., "1 2 3")
- Returns NULL-terminated array of strings

#### `int ft_arraylength(int argc, char **argv)`
- Calculates total number of integers across all arguments
- Used for memory allocation

### Stack Operations (`list_functions.c`)

#### `t_stack *fill_node(int argc, char **argv)`
- Creates the initial stack from validated arguments
- Allocates and links nodes in a doubly-linked list

#### `void free_list(t_stack *stack)`
- Frees all memory allocated for a stack
- Prevents memory leaks

#### `int stack_size(t_stack *stack_a)`
- Returns the number of elements in a stack

#### `t_stack *ft_last_item(t_stack *stack)`
- Returns pointer to the last element in a stack

#### `void print_list(t_stack *stack_a)`
- Debug function to print stack contents

### Swap Operations (`swap_functions.c`)

#### `void sa(t_stack **stack_a)`
- Swaps the first two elements of stack a
- Prints "sa" to stdout

#### `void sb(t_stack **stack_b)`
- Swaps the first two elements of stack b
- Prints "sb" to stdout

#### `void ss(t_stack **stack_a, t_stack **stack_b)`
- Performs sa and sb simultaneously
- Prints "ss" to stdout

### Push Operations (`push_functions.c`)

#### `void pa(t_stack **stack_a, t_stack **stack_b)`
- Pushes top element from stack b to stack a
- Prints "pa" to stdout

#### `void pb(t_stack **stack_a, t_stack **stack_b)`
- Pushes top element from stack a to stack b
- Prints "pb" to stdout

### Rotate Operations (`rotate_functions.c`)

#### `void ra(t_stack **stack_a)`
- Rotates stack a up (top becomes bottom)
- Prints "ra" to stdout

#### `void rb(t_stack **stack_b)`
- Rotates stack b up (top becomes bottom)
- Prints "rb" to stdout

#### `void rr(t_stack **stack_a, t_stack **stack_b)`
- Performs ra and rb simultaneously
- Prints "rr" to stdout

### Reverse Rotate Operations (`rev_rotate_functions.c`)

#### `void rra(t_stack **stack_a)`
- Rotates stack a down (bottom becomes top)
- Prints "rra" to stdout

#### `void rrb(t_stack **stack_b)`
- Rotates stack b down (bottom becomes top)
- Prints "rrb" to stdout

#### `void rrr(t_stack **stack_a, t_stack **stack_b)`
- Performs rra and rrb simultaneously
- Prints "rrr" to stdout

### Sorting Algorithm (`sort_algorithm.c`)

#### `void init_index(t_stack *stack)`
- Assigns index values to each element based on relative order
- Enables radix sort by converting values to indices

#### `int read_bits(t_stack **stack)`
- Calculates number of bits needed for radix sort
- Returns the number of bits in the maximum index

#### `void sort_radix(t_stack **stack_a, t_stack **stack_b)`
- Implements radix sort algorithm
- Sorts elements bit by bit from LSB to MSB

### Sorting Utilities (`sort_functions.c`)

#### `int find_smallest(t_stack *stack)`
- Finds and returns the smallest value in a stack

#### `int find_biggest(t_stack *stack)`
- Finds and returns the biggest value in a stack

#### `void push_to_top(t_stack **stack, int value)`
- Moves a specific value to the top of a stack
- Uses the most efficient rotation direction

#### `int find_position(t_stack *stack, int value)`
- Finds the position of a value in a stack
- Returns 0-based index from top

#### `void push_to_correct_position(t_stack **stack_a, int value)`
- Positions stack a to insert value in correct sorted position

### Simple Sorting (`sort_simples.c`)

#### `int is_sorted(t_stack *stack_a)`
- Checks if a stack is sorted in ascending order
- Returns 1 if sorted, 0 otherwise

#### `void sort_three(t_stack **stack_a)`
- Optimized sorting for exactly 3 elements
- Uses hardcoded cases for maximum efficiency

#### `void sort_four(t_stack **stack_a, t_stack **stack_b)`
- Optimized sorting for exactly 4 elements
- Moves one element to stack b, sorts 3, then reconstructs

#### `void sort_five(t_stack **stack_a, t_stack **stack_b)`
- Optimized sorting for exactly 5 elements
- Moves two smallest elements to stack b, sorts 3, then reconstructs

#### `int ft_count(int argc, t_stack **stack_a, t_stack **stack_b)`
- Main sorting dispatcher
- Chooses appropriate sorting algorithm based on input size

## Testing

The program handles various edge cases:

### Valid Cases
- Already sorted arrays
- Reverse sorted arrays
- Random permutations
- Negative numbers
- Single elements
- Maximum/minimum integer values

### Error Cases
- Duplicate numbers
- Invalid characters
- Integer overflow/underflow
- Empty arguments
- Whitespace-only arguments

### Performance Testing
```bash
# Test with 100 random numbers (should be < 700 operations)
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with 500 random numbers (should be < 5500 operations)
ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

## Performance

The algorithm achieves the following performance benchmarks:

- **3 elements**: Maximum 2 operations
- **4 elements**: Maximum 8 operations
- **5 elements**: Maximum 12 operations
- **100 elements**: < 700 operations (target)
- **500 elements**: < 5500 operations (target)

## Memory Management

- All dynamically allocated memory is properly freed
- No memory leaks (validated with Valgrind)
- Robust error handling with proper cleanup

## Author

Created as part of the 42 School curriculum.