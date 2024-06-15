#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototype
void polyfit(double *x, double *y, int size, int degree, double *coefficients);

int main() {
    // Example data points
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {2.1, 3.8, 7.2, 11.1, 16.5};
    int size = sizeof(x) / sizeof(x[0]);

    // Degree of the polynomial
    int degree = 2;

    // Array to store coefficients of the polynomial
    double coefficients[degree + 1];

    // Call polyfit function to calculate coefficients
    polyfit(x, y, size, degree, coefficients);

    // Print the coefficients
    printf("Coefficients of the polynomial:\n");
    for (int i = 0; i <= degree; i++) {
        printf("c%d: %f\n", i, coefficients[i]);
    }

    return 0;
}

// Function to calculate the coefficients of the polynomial
void polyfit(double *x, double *y, int size, int degree, double *coefficients) {
    // Allocate memory for the coefficient matrix and the constants vector
    double **A = (double **)malloc((degree + 1) * sizeof(double *));
    double *b = (double *)malloc((degree + 1) * sizeof(double));

    // Fill the coefficient matrix
    for (int i = 0; i <= degree; i++) {
        A[i] = (double *)malloc((degree + 1) * sizeof(double));
        for (int j = 0; j <= degree; j++) {
            A[i][j] = 0;
            for (int k = 0; k < size; k++) {
                A[i][j] += pow(x[k], i + j);
            }
        }
    }

    // Fill the constants vector
    for (int i = 0; i <= degree; i++) {
        b[i] = 0;
        for (int k = 0; k < size; k++) {
            b[i] += pow(x[k], i) * y[k];
        }
    }

    // Solve the system of equations using Gaussian elimination
    for (int i = 0; i <= degree; i++) {
        // Find the maximum element in the current column
        double max = fabs(A[i][i]);
        int maxIndex = i;
        for (int k = i + 1; k <= degree; k++) {
            if (fabs(A[k][i]) > max) {
                max = fabs(A[k][i]);
                maxIndex = k;
            }
        }

        // Swap rows if necessary
        if (maxIndex != i) {
            for (int k = i; k <= degree; k++) {
                double temp = A[maxIndex][k];
                A[maxIndex][k] = A[i][k];
                A[i][k] = temp;
            }
            double temp = b[maxIndex];
            b[maxIndex] = b[i];
            b[i] = temp;
        }

        // Perform row operations to make the matrix upper triangular
        for (int k = i + 1; k <= degree; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j <= degree; j++) {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    // Back substitution to get the coefficients
    for (int i = degree; i >= 0; i--) {
        coefficients[i] = b[i];
        for (int j = i + 1; j <= degree; j++) {
            coefficients[i] -= A[i][j] * coefficients[j];
        }
        coefficients[i] /= A[i][i];
    }

    // Free dynamically allocated memory
    for (int i = 0; i <= degree; i++) {
        free(A[i]);
    }
    free(A);
    free(b);
}
