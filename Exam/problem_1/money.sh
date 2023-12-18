#!/bin/bash

# Compile C program
gcc -o money money.c -lm

#> money.txt

for ((N = 1; N <= 10; N++)); do
#    result=$(./money "$N") >> money.txt
	./money $N >> money.txt
#    echo "$result" >> money.txt
done


