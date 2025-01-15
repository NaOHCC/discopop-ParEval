/* forward declare fft. computes fourier transform in-place */
void fft(std::vector<std::complex<double>> &x);

/* Compute the inverse fourier transform of x in-place.
   Example:
   
   input: [1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0]
   output: [{0.5,0}, {0.125,0.301777}, {0,-0}, {0.125,0.0517767}, {0,-0}, {0.125,-0.0517767}, {0,-0}, {0.125,-0.301777}]
*/
NO_INLINE void ifft(std::vector<std::complex<double>> &x) {

// Take conjugate of the complex numbers
for (auto &elem : x) {
    elem = std::conj(elem);
}

// Apply fft
fft(x);

// Take conjugate again
for (auto &elem : x) {
    elem = std::conj(elem);
}

// Scale the numbers
for (auto &elem : x) {
    elem /= static_cast<double>(x.size());
}
}