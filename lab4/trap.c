#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char **argv) {

  int N = atoi( argv[1] );	// Convert input to integer. atoi is defined in stdlib.h
  double dx = 2.0 / (N - 1.0);	// compute dx(spacing between x values))
  
//  printf("N = %d\n", N); 
//  printf("i = %i",N);
//  printf("dx = %e\n",dx);
  
  double integral = (1.0 / (1.0 + pow(1.0, 2)) + 1.0 / (1.0 + pow(-1.0, 2))) / 2.0;	// initialize the integral including 1st and last term

  for (int i=1;i<N-1;++i) {
    double x = -1.0 + dx*i;	// compute x_i terms

    integral += 1.0 / (1.0 + x * x);	// middle terms
    
//    printf("x = %e\n",x);
  }
  
  integral *= dx;	// multiply dx to the whole term

//  printf("Integral = %e\n", integral);

  const double pi = 3.141592653589793;
  double absolute_error = fabs(integral - pi / 2.);
//  printf("error = %e\n",absolute_error);
  printf("%d %e\n", N, absolute_error);

  return 0;
  
}
