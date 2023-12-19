#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_points>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    double dx = 8.0 / (N - 1);
    double integral = 0.0;

    double x = -4.0;
    double f = x / (1.0 + fabs(x) + x*x);
    integral += 0.5 * dx * f;

    x = 4.0;
    f = x / (1.0 + fabs(x) + x*x);
    integral += 0.5 * dx * f;

    for (int i = 1; i < N - 1; ++i) {
        x = -4.0 + dx * i;
        f = x / (1.0 + fabs(x) + x*x);
        integral += dx * f;
    }

    printf("%.10f\n", integral);

    return 0;
}

