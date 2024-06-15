# DSP and Linear Algebra Functions in C

This repository contains various implementations of Digital Signal Processing (DSP) and Linear Algebra functions in C. These functions are designed to perform fundamental operations used in signal processing and matrix computations.

## Functions Overview

### 1. auto_correlation.c

Function: void auto_correlation(double* signal, double* result, int N)

Description: Computes the auto-correlation of a given signal.

Working Principle: Auto-correlation measures the similarity of a signal with a delayed version of itself across different time shifts (lags). It is computed using the formula:

R(τ)=1N−τ∑t=0N−τ−1x[t]⋅x[t+τ]R(τ)=N−τ1​∑t=0N−τ−1​x[t]⋅x[t+τ]

where x[t]x[t] is the signal at time tt, ττ is the lag, and NN is the length of the signal.
### 2. build_toeplitz.c

Function: void buildToeplitz(double* arr, int N, double** matrix)

Description: Constructs a Toeplitz matrix from a given array.

Working Principle: A Toeplitz matrix is a matrix in which each descending diagonal from left to right is constant. The function creates a Toeplitz matrix of size N×NN×N based on the elements of the input array arrarr.
### 3. convolve1d.c

Function: void convolve(double* x, int N, double* h, int M, double* y)

Description: Performs 1-dimensional convolution of two signals.

Working Principle: Convolution is a mathematical operation that combines two signals to produce a third signal. It is computed using the formula:

y[n]=∑k=0M−1x[n−k]⋅h[k]y[n]=∑k=0M−1​x[n−k]⋅h[k]

where x[n]x[n] and h[n]h[n] are the input signals, and y[n]y[n] is the output signal.
### 4. fft.c

Function: void fft(double* realIn, double* imagIn, double* realOut, double* imagOut, int n)

Description: Performs Fast Fourier Transform (FFT) assuming input is real.

Working Principle: FFT is an efficient algorithm to compute the Discrete Fourier Transform (DFT) of a signal. This implementation handles real-valued input by recursively dividing the DFT computation into smaller parts, utilizing symmetry properties and complex exponential functions.
### 5. linear_regression.c

Function: void linear_regression(double* x, double* y, int size, double* coefficients)

Description: Performs linear regression to fit a polynomial of specified degree to given data points.

Working Principle: Linear regression finds the best-fit line (or polynomial) to a set of data points. It computes the coefficients of the polynomial using the method of least squares, minimizing the sum of squared differences between the observed values and the values predicted by the linear model.
### 6. lu_decomposition.c

Function: void luDecomposition(double** A, double** L, double** U, int n)

Description: Performs LU decomposition of a square matrix AA.

Working Principle: LU decomposition factorizes a matrix AA into the product of a lower triangular matrix LL and an upper triangular matrix UU. It decomposes AA using Gaussian elimination, preserving the matrix structure for efficient solving of linear systems.
### 7. matrix_inversion.c

Function: void invertMatrix(double** A, double** invA, int n)

Description: Computes the inverse of a square matrix AA using LU decomposition.

Working Principle: Matrix inversion is performed by first decomposing AA into LL and UU matrices using LU decomposition. Then, it solves A⋅invA=IA⋅invA=I using forward and backward substitution, where II is the identity matrix.
### 8. pink_noise_generation.c

Function: void generate_pink_noise(int n, double* pink_noise)

Description: Generates pink noise of specified length.

Working Principle: Pink noise has equal power in each octave, resulting in a 1/f frequency spectrum. This function applies a 1/f^3 filter to white noise to achieve the desired spectral characteristics.
Usage

---

Each function is implemented in its respective C file (auto_correlation.c, build_toeplitz.c, etc.). To use these functions, include the desired .c file in your project and call the corresponding function(s) as demonstrated in their respective README files.

---

License

This project is licensed under the MIT License - see the LICENSE file for details.
