/* Compute the discrete fourier transform of x. Store the result in output.
   Example:

   input: [1, 4, 9, 16]
   output: [30+0i, -8-12i, -10-0i, -8+12i]
*/
NO_INLINE void dft(std::vector<double> const& x, std::vector<std::complex<double>> &output) {
// TODO: implement this function
    output.resize(x.size());
    for (int i = 0; i < x.size(); i++) {
        output[i] = 0;
        for (int j = 0; j < x.size(); j++) {
            output[i] += x[j] * std::exp(std::complex<double>(0, -2 * M_PI * i * j / x.size()));
        }
    }
}