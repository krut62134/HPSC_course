echo "Compiling code..."
mpicc -Wall -o optimize_ring mpi_ring.c -lm
mpicc -Wall -o optimize_reduction mpi_reduction.c -lm

echo "running code..."
mpirun -np 4 ./optimize_ring 1000
mpirun -np 4 ./optimize_reduction 1000
