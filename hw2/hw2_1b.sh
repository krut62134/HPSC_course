#!/bin/bash

total_runs=30

# Create a single output file to store all the data
output_file="hw2_1b.dat"
echo -n > "$output_file"

for run in $(seq 1 $total_runs)
do
    i=1
    max_i=10  # Set the maximum value of i

    while [[ $i -le $max_i ]]
    do
        time ./hw2_1a $((10**i)) >> "$output_file"
        ((i = i + 1))
    done
done

