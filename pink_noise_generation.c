#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototype for the generate_pink_noise function
void generate_pink_noise(int n, double* pink_noise);

// Function to generate a random double between -1 and 1
double random_double() {
    return 2.0 * ((double)rand() / RAND_MAX) - 1.0;
}

int main() {
    // Example input array size
    int n = 8;

    // Allocate memory for the pink noise array
    double* pink_noise = (double*)malloc(sizeof(double) * n);

    // Call the generate_pink_noise function
    generate_pink_noise(n, pink_noise);

    // Print the generated pink noise
    printf("Generated Pink Noise:\n");
    for (int i = 0; i < n; i++) {
        printf("Index %d: %f\n", i, pink_noise[i]);
    }

    // Free allocated memory
    free(pink_noise);

    return 0;
}

// Function to generate pink noise of length n
void generate_pink_noise(int n, double* pink_noise) {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Initialize variables
    double b0 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0;
    double white;

    // Generate pink noise samples
    for (int i = 0; i < n; i++) {
        white = random_double();

        // Apply 1/f^3 filter (6dB per octave)
        b0 = 0.99886 * b0 + white * 0.0555179;
        b1 = 0.99332 * b1 + white * 0.0750759;
        b2 = 0.96900 * b2 + white * 0.1538520;
        b3 = 0.86650 * b3 + white * 0.3104856;
        b4 = 0.55000 * b4 + white * 0.5329522;
        b5 = -0.7616 * b5 - white * 0.0168980;

        // Combine all the filtered random numbers
        pink_noise[i] = b0 + b1 + b2 + b3 + b4 + b5 + white * 0.5362;
    }
}
