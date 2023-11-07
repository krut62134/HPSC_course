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

    unsigned long long N = strtoull(argv[1], NULL, 10);		//Unsigned long long is used as we're gonna take the N value up to 10^10

    srand((unsigned)time(NULL));		//set the random value generator according to time

    unsigned long long points_inside = 0;

    for (unsigned long long i = 0; i < N; i++) {	//Loop to generate N number of random x1 and x2 points
        double x1 = 2.0 * ((double)rand() / (double)RAND_MAX) - 1.0;
        double x2 = 2.0 * ((double)rand() / (double)RAND_MAX) - 1.0;

        if (x1 * x1 + x2 * x2 <= 1.0) {		//adding those points of the vector x=(x1, x2) which are inside the circle of radius 1
            points_inside++;
        }
    }

    double pi_approx = 4.0 * points_inside / N;		//Monte Carlo approximation

    double error = fabs(PI - pi_approx);

    printf("%llu %e\n", N, error);

    return 0;
}

