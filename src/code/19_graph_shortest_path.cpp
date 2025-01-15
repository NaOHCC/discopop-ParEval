/* Return the length of the shortest path from source to dest in the undirected graph defined by the adjacency matrix A.
   A is an NxN adjacency matrix stored in row-major. A is an undirected graph.
   Example:

	 input: [[0, 1, 1, 0], [1, 0, 0, 1], [1, 0, 0, 1], [0, 1, 1, 0]], source=0, dest=3
   output: 2
*/
NO_INLINE int shortestPathLength(std::vector<int> const& A, size_t N, int source, int dest) {
std::vector<int> dist(N, INT_MAX);
	std::vector<int> prev(N, -1);
	std::queue<int> q;
	q.push(source);
	dist[source] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 0; v < N; ++v) {
			if (A[u * N + v] == 1 && dist[v] == INT_MAX) {
				dist[v] = dist[u] + 1;
				prev[v] = u;
				q.push(v);
			}
		}
	}
	if (dist[dest] == INT_MAX) {
		return -1;
	}
	int path_len = 0;
	while (prev[dest]!= -1) {
		path_len++;
		dest = prev[dest];
	}
	return path_len;
}