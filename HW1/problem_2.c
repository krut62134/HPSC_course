#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Defining the function Prob(x)
double Prob(double x) {
    return exp(-pow(x - 2, 2) / 2) / 2.4496028273129427;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s N\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);

    srand(time(NULL));

    double sum_terms = 0.0;

    // Monte Carlo simulation
    for (int i = 1; i <= N; i++) {
        double S = 10.0 * ((double)rand() / (double)RAND_MAX); // Generate random values of S in the range [0, 10)

        double f_S = S * Prob(S);

        sum_terms += f_S;
    }

    // Calculate the approximate integral value
    double I_approx = (10.0 / N) * sum_terms;

    // Print out the approximate integral value
    printf("%lf\n", I_approx);

    return 0;
}

