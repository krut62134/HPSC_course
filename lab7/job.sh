#!/bin/bash
#SBATCH -N 1
#SBATCH -n 64
#SBATCH --partition=debug  # Partition
#SBATCH -t 5  # Job time limit
#SBATCH -o Lab7.o%j  # %j = job ID # Name of stdout output file
#SBATCH -e Lab7.e%j           # Name of stderr error file
#SBATCH --mail-user=kpatel29@umassd.edu
#SBATCH --mail-type=all    # Send email at begin and end of job


module list
pwd
date

# Launch the code..
echo "Run 1 with 2 threads..."
export OMP_NUM_THREADS=2
echo $OMP_NUM_THREADS
./parfor

echo "Run 2 with 64 threads..."
export OMP_NUM_THREADS=64
echo $OMP_NUM_THREADS
./parfor

# ---------------------------------------------------

