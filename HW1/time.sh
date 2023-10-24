#!/bin/bash

i=1
max_i=30  # Set the maximum value of i

# Create a file to store the data
output_file="timing.dat"
echo -n > "$output_file"

while [[ $i -le $max_i ]]
do
    # Record the start time
    start_time=$(date +%s.%N)

    # Run your monte_carlo program with N = 2^i
    ./monte_carlo $((2**i))

    # Record the end time
    end_time=$(date +%s.%N)

    # Calculate the time taken
    elapsed_time=$(echo "$end_time - $start_time" | bc)

    # Append the N and elapsed_time to the data file
    echo "$((2**i)) $elapsed_time" >> "$output_file"

    ((i = i + 1))
done

