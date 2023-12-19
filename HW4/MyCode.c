#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <omp.h>
#include "secret_function.h"

double rand_double(double min, double max) {
    return ((double)rand() / RAND_MAX) * (max - min) + min;
}

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double start_time, end_time;

    srand(rank);

    int N = 10;

    int samples_per_process = N / size;
    int remainder = N % size;

    int local_samples = (rank < remainder) ? samples_per_process + 1 : samples_per_process;

    double *local_x = (double *)malloc(local_samples * sizeof(double));
    double *local_y = (double *)malloc(local_samples * sizeof(double));
    double *local_results = (double *)malloc(local_samples * sizeof(double));

    for (int i = 0; i < local_samples; i++) {
        local_x[i] = rand_double(-512.0, 512.0);
        local_y[i] = rand_double(-512.0, 512.0);
        local_results[i] = secret_function(local_x[i], local_y[i]);
        printf("Process %d, sample %d, with f = %e\n", rank, i+1, local_results[i]);
    }

    double local_min = local_results[0];
    for (int i = 1; i < local_samples; i++) {
        if (local_results[i] < local_min) {
            local_min = local_results[i];
        }
    }

    printf("Process %d of %d local min = %e\n", rank, size, local_min);

    double global_min;
    MPI_Barrier(MPI_COMM_WORLD);
    start_time = omp_get_wtime();

    MPI_Reduce(&local_min, &global_min, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);

    end_time = omp_get_wtime();

    if (rank == 0) {
        printf("Global min = %e\n", global_min);
        printf("MPI Reduction Time: %f seconds\n", end_time - start_time);
    }

    free(local_x);
    free(local_y);
    free(local_results);

    MPI_Finalize();
    return 0;
}

