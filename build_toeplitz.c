#include <stdio.h>
#include <stdlib.h>

// Prototype for the buildToeplitz function
void buildToeplitz(double* arr, int N, double** matrix);

int main() {
    // Example input array and size
    int N = 4;
    double arr[] = {1.0, 2.0, 3.0, 4.0};

    // Allocate memory for the Toeplitz matrix
    double** matrix = (double**)malloc(N * sizeof(double*));
    for (int i = 0; i < N; i++) {
        matrix[i] = (double*)malloc(N * sizeof(double));
    }

    // Call the buildToeplitz function
    buildToeplitz(arr, N, matrix);

    // Print the generated Toeplitz matrix
    printf("Generated Toeplitz Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

// Function to build a Toeplitz matrix
void buildToeplitz(double* arr, int N, double** matrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > j) {
                matrix[i][j] = arr[i - j];
            } else if (i < j) {
                matrix[i][j] = arr[j - i];
            } else {
                matrix[i][j] = arr[0];
            }
        }
    }
}
