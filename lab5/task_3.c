#include <stdio.h>

void residual(double b[2], double x[2], double A[2][2]);

int main() {
    double x[2], x1[2], x2[2], b[2];
    double A[2][2];

    x[0] = 1.0;
    x[1] = -1.0;

    // Fill in values for x1, x2, and b
    x1[0] = 0.9999999;
    x1[1] = -1.0000001;

    x2[0] = 0.4073666;
    x2[1] = -0.1945277;

    b[0] = 0.1869169;
    b[1] = 0.2155734;

    A[0][0] = 0.7073725;
    A[0][1] = 0.5204556;
    A[1][0] = 0.8158208;
    A[1][1] = 0.6002474;

    residual(b, x, A);
    residual(b, x1, A);
    residual(b, x2, A);

    return 0;
}

void residual(double b[2], double x[2], double A[2][2]) {
    double AX[2] = {0}; // Initialize to zero

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            AX[i] += A[i][j] * x[j];
        }
    }

    // Print the residual
    for (int i = 0; i < 2; i++) {
        printf("residual [ %i ] = %1.10e\n", i, b[i] - AX[i]);
    }
}

