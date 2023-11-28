#!/bin/bash

#SBATCH -N 1
#SBATCH -n 128
#SBATCH -p debug
#SBATCH -t 15 
#SBATCH --mail-user=kpatel29@umassd.edu
#SBATCH --mail-type=all

# Specify the output file
output_file="rosenbrock_3b1.dat"

echo "#N Threads Integral Time" >> $output_file

# Loop over thread counts from 2^0 to 2^7
for ((i=0; i<=7; i++)); do
    threads=$((2**i))
    
    # Run the code and append the results to the output file
    ./rosenbrock $threads 100000000 >> $output_file
done

