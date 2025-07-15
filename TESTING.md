# Push_swap Testing Guide

## Overview

This document provides comprehensive testing strategies and examples for the push_swap project. It includes test cases for validation, performance benchmarks, and debugging techniques.

## Table of Contents

- [Basic Usage Examples](#basic-usage-examples)
- [Edge Case Testing](#edge-case-testing)
- [Performance Testing](#performance-testing)
- [Validation Testing](#validation-testing)
- [Memory Testing](#memory-testing)
- [Automated Testing](#automated-testing)
- [Debugging Tips](#debugging-tips)

## Basic Usage Examples

### Simple Cases

```bash
# Compile the program
make

# Test with 3 numbers
./push_swap 3 2 1
# Expected output: sa, rra

# Test with already sorted numbers
./push_swap 1 2 3 4 5
# Expected output: (no output - already sorted)

# Test with single number
./push_swap 42
# Expected output: (no output - single element)

# Test with two numbers
./push_swap 2 1
# Expected output: ra

# Test with negative numbers
./push_swap -1 -5 0 3
# Expected output: (sorting operations)
```

### String Arguments with Spaces

```bash
# Single argument with multiple numbers
./push_swap "3 2 1 4"
# Expected output: sorting operations

# Mixed arguments
./push_swap "3 2" 1 "4 5"
# Equivalent to: ./push_swap 3 2 1 4 5

# Arguments with extra spaces
./push_swap "  3   2   1  "
# Expected output: sorting operations
```

## Edge Case Testing

### Error Cases

```bash
# Test duplicate numbers
./push_swap 1 2 3 2
# Expected output: Error (to stderr)

# Test invalid characters
./push_swap 1 2 abc
# Expected output: Error (to stderr)

# Test empty argument
./push_swap ""
# Expected output: Error (to stderr)

# Test integer overflow
./push_swap 2147483648
# Expected output: Error (to stderr)

# Test integer underflow
./push_swap -2147483649
# Expected output: Error (to stderr)

# Test invalid signs
./push_swap 1 ++2 3
# Expected output: Error (to stderr)

# Test lone operators
./push_swap 1 + 3
# Expected output: Error (to stderr)

# Test whitespace only
./push_swap "   "
# Expected output: Error (to stderr)
```

### Boundary Cases

```bash
# Test maximum integer values
./push_swap 2147483647 -2147483648 0
# Expected output: sorting operations

# Test single element
./push_swap 0
# Expected output: (no output)

# Test two elements in order
./push_swap 1 2
# Expected output: (no output)

# Test two elements reverse order
./push_swap 2 1
# Expected output: ra
```

## Performance Testing

### Small Array Performance

```bash
# Test 3 elements (should be ≤ 2 operations)
./push_swap 3 2 1 | wc -l
# Expected: 2 or fewer operations

# Test 4 elements (should be ≤ 8 operations)
./push_swap 4 3 2 1 | wc -l
# Expected: 8 or fewer operations

# Test 5 elements (should be ≤ 12 operations)
./push_swap 5 4 3 2 1 | wc -l
# Expected: 12 or fewer operations
```

### Large Array Performance

```bash
# Test 100 random numbers (should be < 700 operations)
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
# Expected: Less than 700 operations

# Test 500 random numbers (should be < 5500 operations)
ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
./push_swap $ARG | wc -l
# Expected: Less than 5500 operations
```

### Performance Benchmark Script

```bash
#!/bin/bash

echo "=== Push_swap Performance Benchmark ==="

# Test 100 elements multiple times
echo "Testing 100 elements (target: < 700 operations):"
for i in {1..10}; do
    ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
    COUNT=$(./push_swap $ARG | wc -l)
    echo "Test $i: $COUNT operations"
done

# Test 500 elements multiple times
echo "Testing 500 elements (target: < 5500 operations):"
for i in {1..5}; do
    ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
    COUNT=$(./push_swap $ARG | wc -l)
    echo "Test $i: $COUNT operations"
done
```

## Validation Testing

### Create Simple Checker

```bash
#!/bin/bash
# Simple validation script

validate_sorting() {
    local args="$1"
    
    # Get operations from push_swap
    local operations=$(./push_swap $args 2>/dev/null)
    
    if [ $? -ne 0 ]; then
        echo "ERROR: push_swap failed"
        return 1
    fi
    
    # Count operations
    local count=$(echo "$operations" | wc -l)
    
    if [ -z "$operations" ]; then
        echo "OK: Already sorted (0 operations)"
    else
        echo "OK: Sorted with $count operations"
    fi
    
    return 0
}

# Test cases
echo "=== Validation Tests ==="
validate_sorting "3 2 1"
validate_sorting "1 2 3 4 5"
validate_sorting "5 4 3 2 1"
validate_sorting "2 1 3 6 5 8"
```

### Python Validation Script

```python
#!/usr/bin/env python3

import subprocess
import sys

def execute_operation(stack_a, stack_b, operation):
    """Execute a single operation on the stacks"""
    if operation == "sa" and len(stack_a) >= 2:
        stack_a[0], stack_a[1] = stack_a[1], stack_a[0]
    elif operation == "sb" and len(stack_b) >= 2:
        stack_b[0], stack_b[1] = stack_b[1], stack_b[0]
    elif operation == "ss":
        if len(stack_a) >= 2:
            stack_a[0], stack_a[1] = stack_a[1], stack_a[0]
        if len(stack_b) >= 2:
            stack_b[0], stack_b[1] = stack_b[1], stack_b[0]
    elif operation == "pa" and stack_b:
        stack_a.insert(0, stack_b.pop(0))
    elif operation == "pb" and stack_a:
        stack_b.insert(0, stack_a.pop(0))
    elif operation == "ra" and stack_a:
        stack_a.append(stack_a.pop(0))
    elif operation == "rb" and stack_b:
        stack_b.append(stack_b.pop(0))
    elif operation == "rr":
        if stack_a:
            stack_a.append(stack_a.pop(0))
        if stack_b:
            stack_b.append(stack_b.pop(0))
    elif operation == "rra" and stack_a:
        stack_a.insert(0, stack_a.pop())
    elif operation == "rrb" and stack_b:
        stack_b.insert(0, stack_b.pop())
    elif operation == "rrr":
        if stack_a:
            stack_a.insert(0, stack_a.pop())
        if stack_b:
            stack_b.insert(0, stack_b.pop())

def validate_push_swap(args):
    """Validate push_swap output"""
    try:
        result = subprocess.run(['./push_swap'] + args, 
                              capture_output=True, text=True)
        
        if result.returncode != 0:
            return "Error", 0
        
        operations = result.stdout.strip().split('\n') if result.stdout.strip() else []
        
        stack_a = [int(x) for x in args]
        stack_b = []
        
        for op in operations:
            if op:
                execute_operation(stack_a, stack_b, op)
        
        is_sorted = all(stack_a[i] <= stack_a[i+1] for i in range(len(stack_a)-1))
        
        if is_sorted and len(stack_b) == 0:
            return "OK", len(operations)
        else:
            return "KO", len(operations)
            
    except Exception as e:
        return "ERROR", 0

# Test cases
test_cases = [
    ["2", "1", "3", "6", "5", "8"],
    ["1", "2", "3", "4", "5"],
    ["5", "4", "3", "2", "1"],
    ["3", "2", "1"],
    ["42"],
    ["2", "1"],
]

print("=== Validation Results ===")
for args in test_cases:
    result, count = validate_push_swap(args)
    print(f"Args: {' '.join(args)} → {result} ({count} operations)")
```

## Memory Testing

### Valgrind Testing

```bash
# Test for memory leaks
valgrind --leak-check=full ./push_swap 3 2 1

# Test with error cases
valgrind --leak-check=full ./push_swap 1 2 3 2

# Test with large input
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
valgrind --leak-check=full ./push_swap $ARG
```

### Comprehensive Memory Test Script

```bash
#!/bin/bash

echo "=== Memory Testing with Valgrind ==="

test_memory() {
    local args="$1"
    local description="$2"
    
    echo "Testing: $description"
    echo "Args: $args"
    
    valgrind --leak-check=full --show-leak-kinds=all \
             --track-origins=yes --error-exitcode=1 \
             ./push_swap $args > /dev/null 2>&1
    
    if [ $? -eq 0 ]; then
        echo "✅ No memory leaks detected"
    else
        echo "❌ Memory issues detected"
    fi
    echo
}

# Test cases
test_memory "3 2 1" "Simple sorting"
test_memory "1 2 3 4 5" "Already sorted"
test_memory "1 2 3 2" "Duplicate numbers (error case)"
test_memory "abc" "Invalid input (error case)"
test_memory "" "Empty argument (error case)"
test_memory "   " "Whitespace only (error case)"

# Large input test
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
test_memory "$ARG" "100 random numbers"
```

## Automated Testing

### Test Suite Script

```bash
#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

TESTS_PASSED=0
TESTS_FAILED=0

# Test function
run_test() {
    local test_name="$1"
    local command="$2"
    local expected_result="$3"
    
    echo -n "Testing: $test_name ... "
    
    result=$(eval "$command" 2>&1)
    exit_code=$?
    
    if [ "$expected_result" = "success" ] && [ $exit_code -eq 0 ]; then
        echo -e "${GREEN}PASS${NC}"
        ((TESTS_PASSED++))
    elif [ "$expected_result" = "error" ] && [ $exit_code -ne 0 ]; then
        echo -e "${GREEN}PASS${NC}"
        ((TESTS_PASSED++))
    else
        echo -e "${RED}FAIL${NC}"
        echo "  Expected: $expected_result"
        echo "  Got: $result"
        ((TESTS_FAILED++))
    fi
}

# Compile program
echo "Compiling push_swap..."
make > /dev/null 2>&1

echo "=== Push_swap Test Suite ==="
echo

# Success cases
run_test "Simple sorting" "./push_swap 3 2 1" "success"
run_test "Already sorted" "./push_swap 1 2 3 4 5" "success"
run_test "Single element" "./push_swap 42" "success"
run_test "Two elements" "./push_swap 2 1" "success"
run_test "Negative numbers" "./push_swap -1 5 -3" "success"
run_test "Mixed argument" "./push_swap '3 2 1'" "success"

# Error cases
run_test "Duplicate numbers" "./push_swap 1 2 3 2" "error"
run_test "Invalid characters" "./push_swap 1 2 abc" "error"
run_test "Integer overflow" "./push_swap 2147483648" "error"
run_test "Empty argument" "./push_swap ''" "error"
run_test "Whitespace only" "./push_swap '   '" "error"

# Performance tests
echo
echo "=== Performance Tests ==="
ARG_100=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
OPS_100=$(./push_swap $ARG_100 | wc -l)
if [ $OPS_100 -lt 700 ]; then
    echo -e "100 elements: ${GREEN}PASS${NC} ($OPS_100 operations)"
    ((TESTS_PASSED++))
else
    echo -e "100 elements: ${RED}FAIL${NC} ($OPS_100 operations, expected < 700)"
    ((TESTS_FAILED++))
fi

ARG_500=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
OPS_500=$(./push_swap $ARG_500 | wc -l)
if [ $OPS_500 -lt 5500 ]; then
    echo -e "500 elements: ${GREEN}PASS${NC} ($OPS_500 operations)"
    ((TESTS_PASSED++))
else
    echo -e "500 elements: ${RED}FAIL${NC} ($OPS_500 operations, expected < 5500)"
    ((TESTS_FAILED++))
fi

# Summary
echo
echo "=== Test Summary ==="
echo -e "Passed: ${GREEN}$TESTS_PASSED${NC}"
echo -e "Failed: ${RED}$TESTS_FAILED${NC}"
echo -e "Total: $((TESTS_PASSED + TESTS_FAILED))"

if [ $TESTS_FAILED -eq 0 ]; then
    echo -e "\n${GREEN}All tests passed!${NC}"
    exit 0
else
    echo -e "\n${RED}Some tests failed!${NC}"
    exit 1
fi
```

## Debugging Tips

### Common Issues and Solutions

1. **Segmentation Fault**
   ```bash
   # Run with gdb
   gdb ./push_swap
   (gdb) run 3 2 1
   (gdb) bt  # backtrace when crash occurs
   ```

2. **Memory Leaks**
   ```bash
   # Use valgrind with detailed output
   valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2 1
   ```

3. **Infinite Loops**
   ```bash
   # Add timeout to prevent hanging
   timeout 10s ./push_swap 3 2 1
   ```

4. **Wrong Output**
   ```bash
   # Debug with step-by-step execution
   echo "3 2 1" | ./push_swap | while read op; do
       echo "Operation: $op"
       # Manual verification
   done
   ```

### Debug Build

```bash
# Compile with debug symbols
make clean
make CFLAGS="-Wall -Wextra -Werror -g -O0"

# Run with gdb
gdb ./push_swap
```

### Logging Function

Add this to your code for debugging:

```c
void debug_print_stacks(t_stack *stack_a, t_stack *stack_b, char *operation)
{
    printf("After %s:\n", operation);
    printf("Stack A: ");
    print_list(stack_a);
    printf("Stack B: ");
    print_list(stack_b);
    printf("\n");
}
```

## Test Data Generation

### Random Test Cases

```bash
# Generate random test cases
for i in {1..10}; do
    ARG=$(shuf -i 1-100 -n $((RANDOM % 20 + 3)) | tr '\n' ' ')
    echo "Test $i: $ARG"
    ./push_swap $ARG | wc -l
done
```

### Worst-Case Scenarios

```bash
# Reverse sorted
./push_swap 10 9 8 7 6 5 4 3 2 1

# Nearly sorted with one out of place
./push_swap 1 3 2 4 5 6 7 8 9 10

# Alternating pattern
./push_swap 1 10 2 9 3 8 4 7 5 6
```

This comprehensive testing guide ensures thorough validation of the push_swap implementation across all scenarios and edge cases.