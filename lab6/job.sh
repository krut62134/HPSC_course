#!/bin/bash
#----------------------------------------------------
#SBATCH -J myjob
#SBATCH -o myjob.o%j
#SBATCH -e myjob.e%j
#SBATCH -p shared
#SBATCH -N 1
#SBATCH -n 5
#SBATCH -t 00:05:00
#SBATCH -A SEE230009
#SBATCH --mail-user=YOUR-UMASSD-NAME@umassd.edu
#SBATCH --mail-type=all

echo "Hello"

./trap 10 &
./trap 100 &
./trap 1000 &
./trap 10000 &
./trap 1000000 &

wait # wait until all 5 trap programs are complete before the script continues
echo "Goodbye"
