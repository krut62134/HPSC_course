#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int is_inside_circle(double x, double y) {
    return x * x + y * y <= 1.0;
}

double estimate_pi_mcmc(int num_samples) {
    int inside_circle_count = 0;

    for (int i = 0; i < num_samples; ++i) {
        // Generate random points in the unit square
        double x = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        double y = ((double)rand() / RAND_MAX) * 2.0 - 1.0;

        // Check if the point is inside the unit circle
        if (is_inside_circle(x, y)) {
            inside_circle_count++;
        }
    }

    // Estimated value of pi based on the ratio of points inside the circle
    return (double)inside_circle_count / num_samples * 4.0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <num_samples>\n", argv[0]);
        return 1;
    }

    int num_samples = atoi(argv[1]);
    if (num_samples <= 0) {
        printf("Please enter a valid positive integer for the number of samples.\n");
        return 1;
    }

    srand((unsigned int)time(NULL));

    double pi_estimate = estimate_pi_mcmc(num_samples);
    printf("Estimated value of pi using 2D MCMC: %.20f\n", pi_estimate);

    // Known value of pi up to 20 decimal places
    const double known_pi = 3.14159265358979323846;

    // Calculate and print the error estimate
    double error_estimate = fabs(known_pi - pi_estimate);
    printf("Error estimate: %.20f\n", error_estimate);

    return 0;
}

