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

  MPI_Status status;


  // Ring passing
  // 1) each process passes its local max to the neighbor process.
  // 2) The neighbor gets the new max, decides if that's bigger than their max, and passes on the result
  // This next if-statement implements the ring topology
  // the last process ID is size-1, so the ring topology is: 0->1, 1->2, ... size-1->0
  // rank 0 starts the chain of events by passing to rank 1
  // 
  // NOTE: after ring passing is over, processor 0's rec_number is the global maximum
  double send_number, rec_number;
  if(rank==0) {
    // only the process with rank ID = 0 will be in this block of code.
    // send data to process 1
    send_number = max;
    MPI_Send(&send_number, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
    // receive data from process size-1 (the last process in the ring)
    MPI_Recv(&rec_number, 1, MPI_DOUBLE, size-1, 0, MPI_COMM_WORLD, &status);
  }
  else if( rank == size-1) {
    // receive data from process rank-1 (it "left" neighbor")
    MPI_Recv(&rec_number, 1, MPI_DOUBLE, rank-1, 0, MPI_COMM_WORLD, &status);
    // send data to its "right neighbor", rank 0
    send_number = rec_number > max ? rec_number : max;
    MPI_Send(&send_number, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
  }
  else {
    // receive data from process rank-1 (it "left" neighbor")
    MPI_Recv(&rec_number, 1, MPI_DOUBLE, rank-1, 0, MPI_COMM_WORLD, &status);
    // send data to its "right neighbor" (rank+1)
    send_number = rec_number > max ? rec_number : max;
    MPI_Send(&send_number, 1, MPI_DOUBLE, rank+1, 0, MPI_COMM_WORLD);
  }
  printf("Process %i send %1.3e and recieved %1.3e\n", rank, send_number, rec_number );
  if(rank==0) {
    printf("Global max is %1.3e\n", rec_number);
  }

  MPI_Finalize(); // programs should always perform a "graceful" shutdown
  return 0;
}
