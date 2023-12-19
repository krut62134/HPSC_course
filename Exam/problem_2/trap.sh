#!/bin/bash

gcc -o trap trap.c -lm

for N in 10 20 50 100 1000; do
    ./trap $N >> trap.txt

done

