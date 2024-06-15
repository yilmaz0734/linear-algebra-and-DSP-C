#include <stdio.h>
#include <stdlib.h>

// Prototype for the luDecomposition function
void luDecomposition(double** A, double** L, double** U, int n);

// Function to print a matrix
void printMatrix(double** matrix, int n);

int main() {
    // Example input matrix (must be square)
    int n = 3;
    double* inputMatrix[3];
    double mat[3][3] = {
        {2.0, -1.0, -2.0},
        {-4.0, 6.0, 3.0},
        {-4.0, -2.0, 8.0}
    };
    
    // Initialize input matrix pointers
    for (int i = 0; i < n; i++) {
        inputMatrix[i] = mat[i];
    }

    // Allocate memory for L and U matrices
    double** L = (double**)malloc(n * sizeof(double*));
    double** U = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        L[i] = (double*)malloc(n * sizeof(double));
        U[i] = (double*)malloc(n * sizeof(double));
    }

    // Call the luDecomposition function
    luDecomposition(inputMatrix, L, U, n);

    // Print the resulting L and U matrices
    printf("L matrix:\n");
    printMatrix(L, n);
    
    printf("U matrix:\n");
    printMatrix(U, n);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(L[i]);
        free(U[i]);
    }
    free(L);
    free(U);

    return 0;
}

// Function to perform LU decomposition
void luDecomposition(double** A, double** L, double** U, int n) {
    for (int i = 0; i < n; i++) {
        // Upper triangular matrix U
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += (L[i][j] * U[j][k]);
            }
            U[i][k] = A[i][k] - sum;
        }

        // Lower triangular matrix L
        for (int k = i; k < n; k++) {
            if (i == k)
                L[i][i] = 1; // Diagonal as 1
            else {
                double sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += (L[k][j] * U[j][i]);
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}
