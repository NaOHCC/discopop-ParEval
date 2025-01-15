struct COOElement {
   size_t row, column;
   double value;
};

/* Factorize the sparse matrix A into A=LU where L is a lower triangular matrix and U is an upper triangular matrix.
   A is a sparse NxN matrix stored in COO format.
   Example:

   input: A=[{0,0,4}, {0,1,3}, {1,0,6}, {1,1,3}]
   output: L=[{0,0,1},{1,0,1.5}, {1,1,1}] U=[{0,0,4}, {0,1,3}, {1,1,-1.5}]
*/
NO_INLINE void luFactorize(std::vector<COOElement> const& A, std::vector<double> &L, std::vector<double> &U, size_t N) {

// Assuming A is sorted by row and then by column
L.clear();
U.clear();

// Initialize L and U with zeros
L.resize(N * N, 0);
U.resize(N * N, 0);

// Create a map for quick access to A's elements
std::map<std::pair<size_t, size_t>, double> A_map;
for (const auto& elem : A) {
    A_map[{elem.row, elem.column}] = elem.value;
}

// LU decomposition algorithm
for (size_t i = 0; i < N; ++i) {
    // U(i, k) = A(i, k) - sum(L(i, j) * U(j, k))
    for (size_t k = i; k < N; ++k) {
        double sum = 0.0;
        for (size_t j = 0; j < i; ++j) {
            sum += L[i * N + j] * U[j * N + k];
        }
        U[i * N + k] = A_map[{i, k}] - sum;
    }

    // L(k, i) = (A(k, i) - sum(L(k, j) * U(j, i))) / U(i, i)
    for (size_t k = i + 1; k < N; ++k) {
        double sum = 0.0;
        for (size_t j = 0; j < i; ++j) {
            sum += L[k * N + j] * U[j * N + i];
        }
        L[k * N + i] = (A_map[{k, i}] - sum) / U[i * N + i];
    }

    // L(i, i) = 1
    L[i * N + i] = 1.0;
}
}