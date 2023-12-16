#!/bin/bash



# Loop through N values from 10^1 to 10^10
for (( i=1; i<=12; i++ )); do
    N=$((10**i))
    
    # Loop through the number of threads from 1 to 10
    for (( threads=10; threads<=100; threads+10 )); do
        ./mcmc_parallel $N $threads >> "mcmc_parallel.dat"
    done
done

