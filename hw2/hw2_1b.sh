#!/bin/bash

total_runs=10

# Create a single output file to store all the data
output_file="hw2_1b.dat"
echo -n > "$output_file"

# Define the function to run your C program
run_c_program() {
    i=$1
    ./hw2_1a $((10**i))
}

export -f run_c_program  # Export the function to be used by parallel

for run in $(seq 1 $total_runs)
do
    seq 10 | parallel -j0 run_c_program {} >> "$output_file"
done

