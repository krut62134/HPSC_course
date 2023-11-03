#!/bin/bash

i=1
max_i=30  # Set the maximum value of i

# Create a file to store the data
output_file="problem_2.dat"
echo -n > "$output_file"

while [[ $i -le $max_i ]]
do
    ./problem_2 $((2**i)) >> "$output_file"
    ((i = i + 1))
done

