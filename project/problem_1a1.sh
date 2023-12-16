#!/bin/bash

i=1
max_i=9

j=1
max_j=2

while [[ $j -le $max_j ]]
do
  threads=$((5*j))
  while [[ $i -le $max_i ]]
  do
    echo "$(./mcmc_parallel $((10**i)) $threads)"
    ((i = i + 1))
  done
  ((j = j + 1))
done
