#include <stdio.h>
#include <stdlib.h>

// Prototypes for the auxiliary functions
static void luDecomposition(double** A, double** L, double** U, int n);
static void forwardSubstitution(double** L, double* y, double* b, int n);
static void backwardSubstitution(double** U, double* x, double* y, int n);
static void invertMatrix(double** A, double** invA, int n);

// Function to print a matrix
void printMatrix(double** matrix, int n);

int main() {
    // Example input matrix (must be square and invertible)
    int n = 3;
    double* inputMatrix[3];
    double mat[3][3] = {
        {4.0, 3.0, 2.0},
        {2.0, 1.0, 5.0},
        {6.0, 7.0, 8.0}
    };

    // Initialize input matrix pointers
    for (int i = 0; i < n; i++) {
        inputMatrix[i] = mat[i];
    }

    // Allocate memory for the inverse matrix
    double** invMatrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        invMatrix[i] = (double*)malloc(n * sizeof(double));
    }

    // Call the invertMatrix function
    invertMatrix(inputMatrix, invMatrix, n);

    // Print the resulting inverse matrix
    printf("Inverse Matrix:\n");
    printMatrix(invMatrix, n);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(invMatrix[i]);
    }
    free(invMatrix);

    return 0;
}

// Function to perform LU decomposition
static void luDecomposition(double** A, double** L, double** U, int n) {
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

// Function to perform forward substitution
static void forwardSubstitution(double** L, double* y, double* b, int n) {
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = b[i] - sum;
    }
}

// Function to perform backward substitution
static void backwardSubstitution(double** U, double* x, double* y, int n) {
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }
}

// Function to invert a matrix using LU decomposition
static void invertMatrix(double** A, double** invA, int n) {
    double** L = (double**)malloc(n * sizeof(double*));
    double** U = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        L[i] = (double*)malloc(n * sizeof(double));
        U[i] = (double*)malloc(n * sizeof(double));
    }

    luDecomposition(A, L, U, n);

    double* y = (double*)malloc(n * sizeof(double));
    double* x = (double*)malloc(n * sizeof(double));
    double* b = (double*)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[j] = (i == j) ? 1 : 0;
        }

        forwardSubstitution(L, y, b, n);
        backwardSubstitution(U, x, y, n);

        for (int j = 0; j < n; j++) {
            invA[j][i] = x[j];
        }
    }

    for (int i = 0; i < n; i++) {
        free(L[i]);
        free(U[i]);
    }
    free(L);
    free(U);
    free(y);
    free(x);
    free(b);
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
