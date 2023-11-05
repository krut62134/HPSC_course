#!/bin/bash

# Number of times to execute the script
total_executions=100

# Output file to store the data
output_file="hw2_1b_parallel.dat"

# Clear the output file if it exists (uncomment this if you want to start with a fresh file each time)
# > "$output_file"

# Use parallel to execute the script concurrently
parallel -j "$(nproc)" bash parallel_1.sh '>>' "$output_file" ::: $(seq "$total_executions")

