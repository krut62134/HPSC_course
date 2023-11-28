#!/bin/bash

i=1
max_i=9  # Set the maximum value of i

while [[ $i -le $max_i ]]
do
    echo "$(./montecarlo_parallel $((10**i)))"
    ((i = i + 1))
done

