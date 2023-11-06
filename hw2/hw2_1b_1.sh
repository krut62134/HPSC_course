#!/bin/bash

i=2
max_i=8  # Set the maximum value of i

while [[ $i -le $max_i ]]
do
    echo "$(./hw2_1a $((10**i)))"
    ((i = i + 1))
done

