// prime.c

#include <stdio.h>

void checkPrime(int N)
{
    int flag = 1;

    // loop to iterate through 2 to N/2, test if divisible
    for (int i = 2; i <= N / 2; i++) {
        if (N % i == 0) {
            flag = 0;
            break;
        }
    }

    if (flag) {
        printf("The number %d is a Prime Number\n", N);
    }
}

