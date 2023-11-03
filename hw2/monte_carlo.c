#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//defining the value of pi
#define PI 3.14159265358979323846

//defininf the function f(x)
double function(double x) {
    return 1.0 / (1.0 + x * x);
}

int main(int argc, char *argv[]) {	//to confirm that the correct value of N is provided, if not, print how to use the code
    if (argc != 2) {
        printf("Usage: %s N\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);	//interpret the value of N from the command line

    srand(time(NULL));	//random number generator with current time

    double sum_terms = 0.0;

    //monte-carlo simulation
    for (int i = 1; i <= N; i++) {

        double xi = 2.0 * ((double)rand() / (double)RAND_MAX) - 1.0; //generates random values of xi from 0 to 1 and multiplies it by 2, then substracting 1 so that we get values fromm -1 to 1
        
	double f_xi = function(xi);

        sum_terms += f_xi;
    }

    //defining the value of V
    double V = 2.0;

    //
    double I1_approx = (V / N) * sum_terms;

    //defining the true valuee of I_1 from the integral which is pi/2
    double I1_true = PI / 2.0;

    //calculates the error E(N)
    double error = fabs(I1_true - I1_approx);

    //print out the result
//    printf("Approximate I1(N): %lf\n", I1_approx);
//    printf("True I1: %lf\n", I1_true);
//    printf("Error E(N): %lf\n", error);
    // Print N and E(N) as an array
    printf("%d %lf\n", N, error);
    return 0;
}

