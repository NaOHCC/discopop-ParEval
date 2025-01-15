/* Compute the fourier transform of x. Store real part of results in r and imaginary in i.
   Example:

   input: [1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0]
   output: r: [4, 1, 0, 1, 0, 1, 0, 1] i: [0, -2.41421, 0, -0.414214, 0, 0.414214, 0, 2.41421]
*/
NO_INLINE void fft(std::vector<std::complex<double>> const& x, std::vector<double> &r, std::vector<double> &i) {
int n = x.size();
    if (n == 0) return;
    if (n == 1) {
        r[0] = x[0].real();
        i[0] = x[0].imag();
        return;
    }
    std::vector<std::complex<double>> x_even(n / 2);
    std::vector<std::complex<double>> x_odd(n / 2);
    for (int i = 0; i < n / 2; i++) {
        x_even[i] = x[2 * i];
        x_odd[i] = x[2 * i + 1];
    }
    std::vector<double> r_even(n / 2);
    std::vector<double> i_even(n / 2);
    std::vector<double> r_odd(n / 2);
    std::vector<double> i_odd(n / 2);
    fft(x_even, r_even, i_even);
    fft(x_odd, r_odd, i_odd);
    for (int k = 0; k < n / 2; k++) {
        std::complex<double> z = std::polar(1.0, -2 * M_PI * k / n) * std::complex<double>(r_odd[k], i_odd[k]);
        r[k] = r_even[k] + z.real();
        i[k] = i_even[k] + z.imag();
        r[k + n / 2] = r_even[k] - z.real();
        i[k + n / 2] = i_even[k] - z.imag();
    }
}