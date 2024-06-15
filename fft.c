#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Prototype for the fft function
void fft(double* realIn, double* imagIn, double* realOut, double* imagOut, int n);

int main() {
    // Example input array size (must be a power of 2)
    int n = 8;

    // Allocate memory for input and output arrays
    double* realIn = (double*)malloc(sizeof(double) * n);
    double* imagIn = (double*)calloc(n, sizeof(double)); // Initialize to 0
    double* realOut = (double*)malloc(sizeof(double) * n);
    double* imagOut = (double*)malloc(sizeof(double) * n);

    // Example real input (sine wave for simplicity)
    for (int i = 0; i < n; i++) {
        realIn[i] = sin(2 * PI * i / n);
        imagIn[i] = 0; // Imaginary part is 0 for real input
    }

    // Call the FFT function
    fft(realIn, imagIn, realOut, imagOut, n);

    // Print the output
    printf("FFT Output:\n");
    for (int i = 0; i < n; i++) {
        printf("Index %d: Real = %f, Imag = %f\n", i, realOut[i], imagOut[i]);
    }

    // Free allocated memory
    free(realIn);
    free(imagIn);
    free(realOut);
    free(imagOut);

    return 0;
}

// Implement the fft function here
void fft(double* realIn, double* imagIn, double* realOut, double* imagOut, int n) {
    if (n <= 1) return;

    // Divide the array and conquer
    double* evenReal = (double*)malloc(sizeof(double) * (n / 2));
    double* oddReal = (double*)malloc(sizeof(double) * (n / 2));
    double* evenImag = (double*)malloc(sizeof(double) * (n / 2));
    double* oddImag = (double*)malloc(sizeof(double) * (n / 2));

    for (int i = 0; i < n / 2; i++) {
        evenReal[i] = realIn[2 * i];
        oddReal[i] = realIn[2 * i + 1];
        evenImag[i] = imagIn[2 * i];
        oddImag[i] = imagIn[2 * i + 1];
    }

    fft(evenReal, evenImag, evenReal, evenImag, n / 2);
    fft(oddReal, oddImag, oddReal, oddImag, n / 2);

    for (int k = 0; k < n / 2; k++) {
        double cosTerm = cos(-2 * PI * k / n);
        double sinTerm = sin(-2 * PI * k / n);
        realOut[k] = evenReal[k] + cosTerm * oddReal[k] - sinTerm * oddImag[k];
        imagOut[k] = evenImag[k] + cosTerm * oddImag[k] + sinTerm * oddReal[k];
        realOut[k + n / 2] = evenReal[k] - (cosTerm * oddReal[k] - sinTerm * oddImag[k]);
        imagOut[k + n / 2] = evenImag[k] - (cosTerm * oddImag[k] + sinTerm * oddReal[k]);
    }

    free(evenReal);
    free(oddReal);
    free(evenImag);
    free(oddImag);
}
