/* Factorize the matrix A into A=LU where L is a lower triangular matrix and U is an upper triangular matrix.
   Store the results for L and U into the original matrix A. 
   A is an NxN matrix stored in row-major.
   Example:

   input: [[4, 3], [6, 3]]
   output: [[4, 3], [1.5, -1.5]]
*/
NO_INLINE void luFactorize(std::vector<double> &A, size_t N) {
for (size_t i = 0; i < N; i++) {
    for (size_t j = i + 1; j < N; j++) {
      A[j * N + i] = A[j * N + i] / A[i * N + i];
      for (size_t k = i + 1; k < N; k++) {
        A[j * N + k] = A[j * N + k] - A[j * N + i] * A[i * N + k];
      }
    }
  }
}