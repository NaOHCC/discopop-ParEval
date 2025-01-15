/* Return the number of vertices in the largest component of the undirected graph defined by the adjacency matrix A.
   A is an NxN adjacency matrix stored in row-major. A is an undirected graph.
   Example:

	 input: [[0, 1, 0, 0], [1, 0, 0, 0], [0, 0, 0, 1], [0, 0, 1, 0]]
   output: 2
*/
NO_INLINE int largestComponent(std::vector<int> const& A, size_t N) {
std::vector<bool> visited(N, false);
  std::vector<int> component(N, 0);
  int max_component = 0;

  for (size_t i = 0; i < N; i++) {
    if (!visited[i]) {
      int size = 0;
      std::queue<int> q;
      q.push(i);
      visited[i] = true;
      while (!q.empty()) {
        int v = q.front();
        q.pop();
        size++;
        for (size_t j = 0; j < N; j++) {
          if (A[v * N + j] == 1 &&!visited[j]) {
            q.push(j);
            visited[j] = true;
          }
        }
      }
      component[i] = size;
      max_component = std::max(max_component, size);
    }
  }

  return max_component;
}