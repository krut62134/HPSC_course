#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <mpi.h>

// will sample any dim-dimensional box of size [a,b]^dim
// the random point is stored in the array x
void sample_rand(const double a, const double b ,const int dim, double *x) {

  for(int i=0;i<dim;++i) {
    double tmp = ((double) rand())/((double) RAND_MAX);
    x[i] = (b-a)*tmp + a;
  }

}

double logL(double x1,double x2) { 
  return -(1.-x1)*(1.-x1) -100.*(x2-x1*x1)*(x2-x1*x1);
}

int main(int argc, char **argv)
{
  int rank, size;

  MPI_Init (&argc, &argv);      // initializes MPI
  MPI_Comm_rank (MPI_COMM_WORLD, &rank); // get current MPI-process ID. O, 1, ...
  MPI_Comm_size (MPI_COMM_WORLD, &size); // get the total number of processes

  long N = atol( argv[1] ); 
  srand(time(NULL) * rank); // each MPI process gets a unique seed

  const int dim = 2;
  double x[dim];  // array of random numbers


  // search for the function's maximum
  double max = -1;
  for(long int i=1; i<=N; ++i) {
    sample_rand(-5.,5.,dim,x);
    double f_i = exp(logL(x[0],x[1]));
    if( f_i > max) {
      max = f_i;
    }
  }

  printf("Process %d of %d local max = %1.5e\n", rank, size, max );

  // max reduction
  double x_process_max = max; // this is the maximum found by the process
  double x_max=-100; // processor 0 will hold the global maximum
  MPI_Reduce(&x_process_max,&x_max,1,MPI_DOUBLE,MPI_MAX,0,MPI_COMM_WORLD);
  MPI_Barrier(MPI_COMM_WORLD); // NOTE THE BARRIER TO HELP WITH OUTPUT LOOKING NICER

  // print some of the results
  printf("Process ID %i, x = %f, max x = %f\n",rank, max, x_max);

  // this print is better -- show x_max from rank=0, which is *the* answer we want
  // After you understand how the code works, the above printf can be removed
  MPI_Barrier(MPI_COMM_WORLD);
  if(rank==0){
    printf("Global maximum from process ID %i, x = %f, max x = %f\n",rank, max, x_max);
  }
  

  MPI_Finalize(); // programs should always perform a "graceful" shutdown
  return 0;
}
