/* Compute one iteration of a 3-point 1D jacobi stencil on `input`. Store the results in `output`.
   Each element of `input` will be averaged with its two neighbors and stored in the corresponding element of `output`.
   i.e. output[i] = (input[i-1]+input[i]+input[i+1])/3
   Replace with 0 when reading past the boundaries of `input`.
   Example:

   input: [9, -6, -1, 2, 3]
   output: [1, 2/3, -5/3, 4/3, 5/3]
*/
NO_INLINE void jacobi1D(std::vector<double> const& input, std::vector<double> &output) {
// YOUR CODE HERE
    for (int i = 1; i < input.size() - 1; i++) {
        output[i] = (input[i - 1] + input[i] + input[i + 1]) / 3;
    }
}