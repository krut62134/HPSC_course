#!/bin/bash

total_runs=30

# Create a single output file to store all the data
output_file="hw2_1b_.dat"
echo -n > "$output_file"

for run in $(seq 1 $total_runs)
do
    while [[ 1 -le 10 ]]
    do
        ./hw2_1a $((10**i)) >> "$output_file"
        ((i = i + 1))
    done
done
