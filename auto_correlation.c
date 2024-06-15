#include <stdio.h>

// Function prototype
void auto_correlation(double* signal, double* result, int N);

int main() {
    // Example signal
    double signal[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int N = sizeof(signal) / sizeof(signal[0]);

    // Array to store auto-correlation results
    double result[N];

    // Compute auto-correlation
    auto_correlation(signal, result, N);

    // Print the results
    printf("Auto-correlation results:\n");
    for (int lag = 0; lag < N; lag++) {
        printf("lag %d: %.3f\n", lag, result[lag]);
    }

    return 0;
}

// Function to calculate the auto-correlation of a signal
void auto_correlation(double* signal, double* result, int N) {
    for (int lag = 0; lag < N; lag++) {
        result[lag] = 0;
        for (int i = 0; i < N - lag; i++) {
            result[lag] += signal[i] * signal[i + lag];
        }
        result[lag] /= (N - lag);
    }
}
