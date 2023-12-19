#!/bin/bash

gcc -o money money.c -lm


for ((N = 1; N <= 10; N++)); do
	./money $N >> money.txt
done


