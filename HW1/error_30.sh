#!/bin/bash

total_runs=30

# Create a single output file to store all the data
output_file="error_combined.dat"
echo -n > "$output_file"

for run in $(seq 1 $total_runs)
do
    i=1
    max_i=30  # Set the maximum value of i

    while [[ $i -le $max_i ]]
    do
        ./monte_carlo $((2**i)) >> "$output_file"
        ((i = i + 1))
    done
done

