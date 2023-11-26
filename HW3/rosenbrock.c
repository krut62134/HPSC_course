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

    printf("Number of threads requested: %d\n", num_threads);
    printf("N = %lli\n", N);

    double x[dim];
    double integral = 0;

    omp_set_num_threads(num_threads);
    double local_integral = 0.0;

    double start_time = omp_get_wtime(); // Start timing

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

    double end_time = omp_get_wtime(); // Stop timing

    integral = (V / N) * local_integral;
    printf("Number of threads used: %d\n", omp_get_max_threads());
    printf("integral = %1.5e\n", integral);
    printf("Time taken: %f seconds\n", end_time - start_time);


    return 0;
}

