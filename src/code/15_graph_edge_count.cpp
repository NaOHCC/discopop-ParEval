/* Count the number of edges in the directed graph defined by the adjacency matrix A.
   A is an NxN adjacency matrix stored in row-major. A represents a directed graph.
   Example:

	 input: [[0, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 1], [1, 1, 1, 0]]
   output: 3
*/
NO_INLINE int edgeCount(std::vector<int> const& A, size_t N) {
int count = 0;
  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < N; ++j) {
      if (A[i * N + j] == 1) {
        ++count;
      }
    }
  }
  return count;
}