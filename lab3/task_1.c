// header file for standerd io (Input/Output) library
#include <stdio.h>
#include <stdlib.h> //for strtod

// main funcion
int main(int argc, char **argv){
	
  double x = strtod(argv[1], NULL);
  
  printf("Hello World!\n");
  printf("argv[ 0 ] = %s\n", argv[0]); // will print executable name
  printf("x passed to program = %s\n",argv[1]); // will print the input passed
  printf("x = %f\n",x); // print the double value
  
  if(x<2) {
    printf("Low CPU usage!\n");
  } else if(x>10){
    printf("High CPU usage!\n");
  } else {
    printf("Moderate CPU usage!\n");
  }
  
  return 0; // every C program should have this part

}
