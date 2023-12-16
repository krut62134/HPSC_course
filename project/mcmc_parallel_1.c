#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>
#include <gmp.h>

int is_inside_circle(double x, double y) {
    return x * x + y * y <= 1.0;
}

void estimate_pi_mcmc(mpf_t pi_estimate, long long int N) {
    int inside_circle_count = 0;

    // Use a different seed for each thread
    unsigned int seed = (unsigned int)time(NULL) + omp_get_thread_num();

    #pragma omp parallel for reduction(+:inside_circle_count) private(seed)
    for (long long int i = 0; i < N; ++i) {
        // Generate random points in the unit square
        double x = ((double)rand_r(&seed) / RAND_MAX) * 2.0 - 1.0;
        double y = ((double)rand_r(&seed) / RAND_MAX) * 2.0 - 1.0;

        // Check if the point is inside the unit circle
        if (is_inside_circle(x, y)) {
            inside_circle_count++;
        }
    }

    // Estimated value of pi based on the ratio of points inside the circle
    mpf_set_d(pi_estimate, (double)inside_circle_count / N * 4.0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <N>\n", argv[0]);
        return 1;
    }

    long long int N = atoll(argv[1]);
    if (N <= 0) {
        printf("Please enter a valid positive integer for the value of N.\n");
        return 1;
    }

    srand((unsigned int)time(NULL));

    // Set the number of threads to 15
    omp_set_num_threads(15);

    // Print the number of threads
    #pragma omp parallel
    {
        #pragma omp single
        printf("Number of threads: %d\n", omp_get_num_threads());
    }

    // Use GMP for higher precision
    mpf_t pi_estimate;
    mpf_init(pi_estimate);

    estimate_pi_mcmc(pi_estimate, N);

    // Known value of pi up to 20 decimal places
    const char* known_pi = "3.14159265358979323846";

    // Print the estimated value of pi with high precision
    char* pi_str = mpf_get_str(NULL, NULL, 10, 0, pi_estimate);
    printf("Estimated value of pi using 2D MCMC: %s\n", pi_str);

    // Calculate and print the error estimate
    mpf_t error_estimate;
    mpf_init(error_estimate);

    mpf_set_str(error_estimate, known_pi, 10);
    mpf_sub(error_estimate, pi_estimate, error_estimate);

    char* error_str = mpf_get_str(NULL, NULL, 10, 0, error_estimate);
    printf("Error estimate: %s\n", error_str);

    mpf_clear(pi_estimate);
    mpf_clear(error_estimate);
    free(pi_str);
    free(error_str);

    return 0;
}

