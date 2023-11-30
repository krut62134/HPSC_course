#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {

	int N = atoi( argv[1] );
	double dx = 2./(N-1);
	double integral = 0.0;

	double x = -1.0;
	double f = 1. / (1. +x*x);
	integral = integral + 0.5*dx*f;

	for (int i=1; i<N; ++i) {
		x = -1. + dx*i;
		f = 1. / (1. + x*x);
		integral = integral + dx*f;
	}

	const double pi = 3.141592653589793;
	double absolute_error = fabs(integral - pi / 2.);
	printf("%i %e %e\n",N,integral,absolute_error);
	return 0;
}
