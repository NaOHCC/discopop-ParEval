/* Solve the linear system Ax=b for x.
   A is an NxN matrix in row-major. x and b have N elements.
   Example:
   
   input: A=[[1,4,2], [1,2,3], [2,1,3]] b=[11, 11, 13]
   output: x=[3, 1, 2]
*/
NO_INLINE void solveLinearSystem(std::vector<double> const& A, std::vector<double> const& b, std::vector<double> &x, size_t N) {
// check if the input is valid
    if (A.size()!= N * N) {
        throw std::invalid_argument("A must be a NxN matrix");
    }
    if (b.size()!= N) {
        throw std::invalid_argument("b must have N elements");
    }
    // create a copy of A
    std::vector<double> A_copy(A);
    // create a copy of b
    std::vector<double> b_copy(b);
    // perform Gaussian elimination
    for (size_t i = 0; i < N; i++) {
        // find the pivot row and swap it with the current row
        size_t pivot_row = i;
        for (size_t j = i + 1; j < N; j++) {
            if (std::abs(A_copy[j * N + i]) > std::abs(A_copy[pivot_row * N + i])) {
                pivot_row = j;
            }
        }
        if (pivot_row!= i) {
            // swap the current row with the pivot row
            for (size_t j = 0; j < N; j++) {
                std::swap(A_copy[i * N + j], A_copy[pivot_row * N + j]);
            }
            std::swap(b_copy[i], b_copy[pivot_row]);
        }
        // eliminate the current row
        for (size_t j = i + 1; j < N; j++) {
            double factor = A_copy[j * N + i] / A_copy[i * N + i];
            for (size_t k = 0; k < N; k++) {
                A_copy[j * N + k] -= factor * A_copy[i * N + k];
            }
            b_copy[j] -= factor * b_copy[i];
        }
    }
    // back substitution
    x[N - 1] = b_copy[N - 1] / A_copy[(N - 1) * N + (N - 1)];
    for (size_t i = N - 2; i < N; i--) {
        double sum = 0;
        for (size_t j = i + 1; j < N; j++) {
            sum += A_copy[i * N + j] * x[j];
        }
        x[i] = (b_copy[i] - sum) / A_copy[i * N + i];
    }
}