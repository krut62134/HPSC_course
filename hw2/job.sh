#!/bin/bash
#SBATCH -N 1
#SBATCH --ntasks-per-node=1
#SBATCH --partition=shared  # Partition
#SBATCH -t 00:05:00  # Job time limit
#SBATCH -o hw2_1c.o%j  # %j = job ID # Name of stdout output file
#SBATCH -e hw2_1c.e%j           # Name of stderr error file
#SBATCH --mail-user=kpatel29@umassd.edu
#SBATCH --mail-type=all    # Send email at begin and end of job


module list
pwd
date

# Launch the code..
bash hw2_1b_1.sh >> hw2_1c_anvil.dat


# ---------------------------------------------------

