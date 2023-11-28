#!/bin/bash

#SBATCH -N 1
#SBATCH -n 128
#SBATCH -p debug
#SBATCH -t 30 
#SBATCH --mail-user=kpatel29@umassd.edu
#SBATCH --mail-type=all

# Specify the output file
output_file="rosenbrock_3c1.dat"

echo "#Threads N Integral Time" >> $output_file

# Loop over thread counts from 2^0 to 2^7
for ((i=0; i<=7; i++)); do
    threads=$((2**i))
    N=$(($threads*1000000000))
    # Run the code and append the results to the output file
    ./rosenbrock $threads $N >> $output_file
done

