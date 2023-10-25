#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    srand(time(NULL));

    int N = atoi(argv[1]);
    FILE *output_file = fopen(argv[2], "w");

    for (int i = 0; i < N; ++i) {
        int rand_int = rand();
        double x = (double)rand_int / RAND_MAX;
        fprintf(output_file, "%lf\n", x);
    }

    fclose(output_file);

    return 0;
}

