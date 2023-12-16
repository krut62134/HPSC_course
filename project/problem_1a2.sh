#!/bin/bash

# Number of times to execute the script
total_executions=1

# Output file to store the data

output_file="problem_1a.dat"

#echo "#N Error" >> $output_file
# Clear the output file if it exists (uncomment this if you want to start with a fresh file each time)
# > "$output_file"

parallel -j 11 "bash problem_1a1.sh >> $output_file" ::: $(seq "$total_executions")
#bash problem_1a1.sh >> $output_file ::: $(seq "$total_executions")

#oinclude <stdlib.h>

