#include <stdio.h>
#include <stdlib.h>

// Prototype for the convolve function
void convolve(double* x, int N, double* h, int M, double* y);

int main() {
    // Example input arrays and their sizes
    int N = 5;
    double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};

    int M = 3;
    double h[] = {0.2, 0.5, 0.3};

    // Allocate memory for the output array
    int resultSize = N + M - 1;
    double* y = (double*)malloc(resultSize * sizeof(double));

    // Call the convolve function
    convolve(x, N, h, M, y);

    // Print the convolution result
    printf("Convolution Result:\n");
    for (int i = 0; i < resultSize; i++) {
        printf("y[%d] = %f\n", i, y[i]);
    }

    // Free allocated memory
    free(y);

    return 0;
}

// Function to perform convolution
void convolve(double* x, int N, double* h, int M, double* y) {
    int resultSize = N + M - 1;

    for (int n = 0; n < resultSize; n++) {
        y[n] = 0.0;
        for (int k = 0; k <= n; k++) {
            if (k < N && n - k < M) {
                y[n] += x[k] * h[n - k];
            }
        }
    }
}
