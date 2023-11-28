#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <omp.h>

#define I_act 1024

double sample_interval(const double a, const double b, unsigned int *seed) {

  double x =((double) rand_r(seed))/((double) RAND_MAX);
  return (b-a)*x + a;

}


double func(double *x, int dim) {

  double f = 1.0;

  for(int i=0;i<dim;i++) {
    f += x[i]; //f=x1+x2+x3,....+x10
  }

  return f;
}

int main (int argc, char **argv) {
  
  double start_time = omp_get_wtime();

  const int dim = 10;

  const double V = 1024;
  const double xL = -1.0;
  const double xR = 1.0;

  srand(time(NULL));
  long long int N = atoll(argv[1]);

//  printf("N = %lli\n",N);

  double x[dim];
  double integral = 0;


  omp_set_num_threads(15);
  double local_integral = 0.0;


  #pragma omp parallel private(x) reduction(+:local_integral)
  {
    unsigned int seed = (unsigned int)(time(NULL) + omp_get_thread_num()); // Different seed for each thread

    #pragma omp for
    for(long long int i=1; i<=N; ++i) {

      for(int j=0;j<dim;++j) {
        x[j] = sample_interval(xL,xR,&seed);
      }

      double f_i = func(x,dim);
      local_integral += f_i;
    }
  }


  integral = (V/N)*local_integral;
//  printf("Number of threads used : %d\n", omp_get_max_threads());
//  printf("integral = %1.5e\n", integral);
  
  double error = fabs(I_act - integral);
//  printf("%llu %e\n", N, error);
  
  double end_time = omp_get_wtime();
  double total_time = end_time - start_time;
  printf("ellapsed time: %f\n", total_time);
  
  return 0;
}
