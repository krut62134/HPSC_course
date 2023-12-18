#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <number_of_points> <number_of_threads>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    int num_threads = atoi(argv[2]);
    double dx = 8.0 / (N - 1);
    double integral = 0.0;

    double *f_values = (double *)malloc(N * sizeof(double));

#pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < N; ++i) {
        double x = -4.0 + dx * i;
        f_values[i] = x / (1.0 + fabs(x) + x * x);
    }

    integral += 0.5 * dx * f_values[0];
    integral += 0.5 * dx * f_values[N - 1];

    for (int i = 1; i < N - 1; ++i) {
        integral += dx * f_values[i];
    }

    printf("%.10f\n", integral);

    free(f_values);

    return 0;
}

