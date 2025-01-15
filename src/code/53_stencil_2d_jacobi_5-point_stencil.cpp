/* Compute one iteration of a 5-point 2D jacobi stencil on `input`. Store the results in `output`.
   Each element of `input` will be averaged with its four neighbors and stored in the corresponding element of `output`.
   i.e. output_{i,j} = (input_{i,j-1} + input_{i,j+1} + input_{i-1,j} + input_{i+1,j} + input_{i,j})/5
   Replace with 0 when reading past the boundaries of `input`.
   `input` and `output` are NxN grids stored in row-major.
   Example:

   input: [[3, 4, 1], [0, 1, 7], [5, 3, 2]]
   output: [[1.4, 1.8, 2.4],[1.8, 3, 2.2], [1.6, 2.2, 2.4]]
*/
NO_INLINE void jacobi2D(std::vector<double> const& input, std::vector<double> &output, size_t N) {
for (size_t i = 1; i < N - 1; ++i) {
    for (size_t j = 1; j < N - 1; ++j) {
      output[i * N + j] = (input[(i - 1) * N + j] + input[(i + 1) * N + j] + input[i * N + j - 1] + input[i * N + j + 1] + input[i * N + j]) / 5;
    }
  }
}