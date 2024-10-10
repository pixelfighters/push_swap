#!/bin/bash

# Generate 500 random integers between 1 and 1000
ARG=$(shuf -i 1-10 -n  5 | tr '\n' ' ')

# Run the push_swap and checker_OS commands with the generated ARG
 ./push_swap $ARG | ./checker_linux $ARG
 echo $ARG
# ./push_swap $ARG | wc -l
 ./push_swap $ARG
