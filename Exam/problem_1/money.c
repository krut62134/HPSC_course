#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_years>\n", argv[0]);
        return 1;
    }

    double principal = 1000.0;
    double interest_rate = 0.05;
    
    int years = atoi(argv[1]);

    if (years < 0) {
        printf("Please enter a non-negative number of years.\n");
        return 1;
    }

    double amount = principal * pow(1 + interest_rate, years);

    printf("%.2f\n", amount);

    return 0;
}

