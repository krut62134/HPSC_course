#include <stdio.h>
#include <math.h>

double rosenbrock_function(double *x, int dim) {
    double f = 0.0;
    for (int i = 0; i < dim - 1; ++i) {
        f += 100 * pow((x[i + 1] - x[i] * x[i]), 2) + pow(1 - x[i], 2);
    }
    return exp(-f); // Taking the exponential of the negative of the Rosenbrock function
}

int main() {
    const int dim = 10;
    double x[dim];

    // Set all values of x to 1
    for (int j = 0; j < dim; ++j) {
        x[j] = 1.0;
    }

    // Evaluate the Rosenbrock function for x = {1, 1, ..., 1}
    double integral = rosenbrock_function(x, dim);

    // Print the result
    printf("Rosenbrock function value for x = {1, 1, ..., 1}: %1.5e\n", integral);

    return 0;
}

