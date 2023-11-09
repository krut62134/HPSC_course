#include <omp.h>
#include <stdio.h>
#include <math.h>

int main() {
    int N = 1000000;
    float b[N];
    float a[N];  // Move the array declaration outside the parallel region

    // Serial portion of the code -- fill up b with integers
    for (int j = 0; j < N; j++) {
        b[j] = j + 1;
    }

    // Parallel portion of the code
    #pragma omp parallel
    {
        // Compute square roots in parallel
        #pragma omp for
        for (int i = 0; i < N; i++) {
            printf("Thread %d working on component %d\n", omp_get_thread_num(), i);
            a[i] = sqrt(b[i]);
        }
    }

    // Serial portion of the code -- print results
    for (int j = 0; j < N; j++) {
        printf("square root of %f is = %f\n", b[j], a[j]);
    }

    return 0;
}

