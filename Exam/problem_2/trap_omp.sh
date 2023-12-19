#!/bin/bash

gcc -o trap_omp trap_omp.c -lm -fopenmp -Wall

for N in 10 20 50 100 1000; do
    ./trap_omp $N 4 >> trap_omp.txt

done

