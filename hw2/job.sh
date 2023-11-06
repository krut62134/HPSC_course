#!/bin/bash

#SBATCH -N 1 
#SBATCH -n 120
#SBATCH -t 60
#SBATCH -p shared
#SBATCH -o hw2_1b_2.o%j  # %j = job ID # Name of stdout output file
#SBATCH -e hw2_1b_2.e%j           # Name of stderr error file
#SBATCH --mail-user=kpatel29@umassd.edu
#SBATCH --mail-type=all

module list

bash hw2_1b_2.sh
