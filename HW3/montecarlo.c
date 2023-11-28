#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

double sample_interval(const double a, const double b) {
    double x = ((double) rand()) / ((double) RAND_MAX);
    return (b - a) * x + a;
}

double func(double *x, int dim) {
    double f = 1.0;
    for (int i = 0; i < dim; ++i) {
        f += x[i]; // f = x1 + x2 + ... + x10
    }
    return f;
}

int main(int argc, char **argv) {
    const int dim = 10; // dimension of the integration region R
    const double V = 1024; // volume of R
    const double xL = -1.0;
    const double xR = 1.0;

    srand(time(NULL));
    long long int N = atoll(argv[1]); // convert command-line input to N = number of points

    printf("N = %lli\n", N);

    double x[dim]; // array of random numbers
    double integral = 0;

//    clock_t start_time = clock(); // Start measuring time

    for (long long int i = 1; i <= N; ++i) {
        for (int j = 0; j < dim; ++j) {
            x[j] = sample_interval(xL, xR);
        }
        double f_i = func(x, dim);
        integral += f_i;
    }

//    clock_t end_time = clock(); // Stop measuring time

    integral = (V / N) * integral;
    printf("integral = %1.5e\n", integral);

//    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
//    printf("Elapsed time: %f seconds\n", elapsed_time);

    return 0;
}

