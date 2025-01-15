/* Compute the fourier transform of x. Store the result in output.
   Example:

   input: [1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0]
   output: [{4,0}, {1,-2.42421}, {0,0}, {1,-0.414214}, {0,0}, {1,0.414214}, {0,0}, {1,2.41421}]
*/
NO_INLINE void fft(std::vector<std::complex<double>> const& x, std::vector<std::complex<double>> &output) {
int n = x.size();
    output.resize(n);

    // base case
    if (n == 1) {
        output[0] = x[0];
        return;
    }

    // radix 2 Cooley-Tukey FFT
    // decompose x into even and odd parts
    std::vector<std::complex<double>> x_even(n/2);
    std::vector<std::complex<double>> x_odd(n/2);
    for (int k = 0; k < n/2; k++) {
        x_even[k] = x[2*k];
        x_odd[k] = x[2*k + 1];
    }

    // recursively compute FFTs of even and odd parts
    std::vector<std::complex<double>> y_even(n/2);
    std::vector<std::complex<double>> y_odd(n/2);
    fft(x_even, y_even);
    fft(x_odd, y_odd);

    // combine results
    for (int k = 0; k < n/2; k++) {
        double kth = -2 * M_PI * k / n;
        output[k] = y_even[k] + std::complex<double>(cos(kth), sin(kth)) * y_odd[k];
        output[k + n/2] = y_even[k] - std::complex<double>(cos(kth), sin(kth)) * y_odd[k];
    }
}