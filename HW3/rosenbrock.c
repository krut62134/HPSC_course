#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <omp.h>

double sample_interval(const double a, const double b, unsigned int *seed) {
    double x = ((double) rand_r(seed)) / ((double) RAND_MAX);
    return (b - a) * x + a;
}

double rosenbrock_function(double *x, int dim) {
    double f = 0.0;
    for (int i = 0; i < dim - 1; ++i) {
        f += 100 * pow((x[i + 1] - x[i] * x[i]), 2) + pow(1 - x[i], 2);
    }
    return exp(-f); // Taking the exponential of the negative of the Rosenbrock function
}

int main(int argc, char **argv) {
    double start_total_time = omp_get_wtime(); // Start timing for the entire program

    if (argc != 3) {
        printf("Usage: %s <number_of_threads> <N>\n", argv[0]);
        return 1;
    }

    int num_threads = atoi(argv[1]);
    long long int N = atoll(argv[2]);

    const int dim = 10;
    const double V = 1024;
    const double xL = -1.0;
    const double xR = 1.0;

    srand(time(NULL));

    // Arrays to store data
    double data[4];  // Thread count, N, Integral, Total Time

    double x[dim];
    double integral = 0;

    omp_set_num_threads(num_threads);
    double local_integral = 0.0;

    #pragma omp parallel private(x) reduction(+:local_integral)
    {
        unsigned int seed = (unsigned int)(time(NULL) + omp_get_thread_num()); // Different seed for each thread

        #pragma omp for
        for (long long int i = 1; i <= N; ++i) {
            for (int j = 0; j < dim; ++j) {
                x[j] = sample_interval(xL, xR, &seed);
            }

            double f_i = rosenbrock_function(x, dim);
            local_integral += f_i;
        }
    }

    integral = (V / N) * local_integral;

    // Set values in the data array
    data[0] = num_threads;
    data[1] = N;
    data[2] = integral;
    double end_total_time = omp_get_wtime(); // Stop timing for the entire program
    data[3] = end_total_time - start_total_time;

    // Print the data in array form
    printf("%1.0f %lli %1.5e %f\n", data[0], (long long int)data[1], data[2], data[3]);

    return 0;
}

