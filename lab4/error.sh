#!/bin/bash

i=1
while [[ 1 -le 30 ]]
do
	./trap $((2**i))
	((i = i + 1))
done
