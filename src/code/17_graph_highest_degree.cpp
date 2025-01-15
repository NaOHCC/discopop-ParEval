/* Compute the highest node degree in the undirected graph. The graph is defined in the adjacency matrix A.
   A is an NxN adjacency matrix stored in row-major. A is an undirected graph.
   Example:

	 input: [[0, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 1], [1, 1, 1, 0]]
   output: 3
*/
NO_INLINE int maxDegree(std::vector<int> const& A, size_t N) {
int max_degree = 0;
  for (size_t i = 0; i < N; ++i) {
    int degree = 0;
    for (size_t j = 0; j < N; ++j) {
      if (A[i * N + j] == 1) {
        ++degree;
      }
    }
    if (degree > max_degree) {
      max_degree = degree;
    }
  }
  return max_degree;
}