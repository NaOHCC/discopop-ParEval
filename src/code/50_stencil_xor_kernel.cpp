/* Set every cell's value to 1 if it has exactly one neighbor that's a 1. Otherwise set it to 0.
   Note that we only consider neighbors and not input_{i,j} when computing output_{i,j}.
   input and output are NxN grids of ints in row-major.
   Example:

   input: [[0, 1, 1, 0],
           [1, 0, 0, 0],
           [0, 0, 0, 0],
           [0, 1, 0, 0]
   output: [[0, 0, 1, 1],
            [1, 0, 0, 1],
            [0, 0, 1, 0],
            [1, 0, 1, 0]]
*/
NO_INLINE void cellsXOR(std::vector<int> const& input, std::vector<int> &output, size_t N) {
for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            int count = 0;
            if (i > 0 && input[i - 1 + j * N] == 1) {
                ++count;
            }
            if (i < N - 1 && input[i + 1 + j * N] == 1) {
                ++count;
            }
            if (j > 0 && input[i + (j - 1) * N] == 1) {
                ++count;
            }
            if (j < N - 1 && input[i + (j + 1) * N] == 1) {
                ++count;
            }
            if (count == 1) {
                output[i + j * N] = 1;
            } else {
                output[i + j * N] = 0;
            }
        }
    }
}