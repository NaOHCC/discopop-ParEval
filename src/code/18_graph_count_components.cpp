/* Count the number of connected components in the undirected graph defined by the adjacency matrix A.
   A is an NxN adjacency matrix stored in row-major. A is an undirected graph.
   Example:

	 input: [[0, 1, 0, 0], [1, 0, 0, 0], [0, 0, 0, 1], [0, 0, 1, 0]]
   output: 2
*/
NO_INLINE int componentCount(std::vector<int> const& A, size_t N) {
std::vector<bool> visited(N, false);
    int count = 0;

    for (size_t i = 0; i < N; ++i) {
        if (!visited[i]) {
            ++count;
            std::stack<size_t> stack;
            stack.push(i);
            visited[i] = true;

            while (!stack.empty()) {
                size_t node = stack.top();
                stack.pop();

                for (size_t j = 0; j < N; ++j) {
                    if (A[node * N + j] &&!visited[j]) {
                        stack.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }

    return count;
}