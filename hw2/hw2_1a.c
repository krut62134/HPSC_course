#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s N\n", argv[0]);
        return 1;
    }

    unsigned long long N = strtoull(argv[1], NULL, 10);

    srand((unsigned)time(NULL));

    unsigned long long points_inside_circle = 0;

    for (unsigned long long i = 0; i < N; i++) {
        double x1 = (double)rand() / RAND_MAX;
        double x2 = (double)rand() / RAND_MAX;

        if (x1 * x1 + x2 * x2 <= 1.0) {
            points_inside_circle++;
        }
    }

    double pi_approx = 4.0 * points_inside_circle / N;

    double error = fabs(PI - pi_approx);

    printf("%llu %e\n", N, error);

    return 0;
}

