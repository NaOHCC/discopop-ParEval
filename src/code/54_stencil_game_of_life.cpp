/* Simulate one generation of Game of Life on `input`. Store the results in `output`.
   A cell is 1 if it is alive and 0 if it is dead.
   If a live cell has fewer than 2 live neighbors then it dies.
   If a live cell has 2 or 3 live neighbors then it lives on.
   If a live cell has more than 3 live neighbords then it dies.
   If a cell is dead and has exactly 3 live neighbors then it becomes alive.
   `input` and `output` are NxN grids stored in row-major.
   Example:

   input:  [[0, 0, 0, 0, 0],
					  [0, 1, 0, 0, 0],
            [0, 1, 1, 0, 0],
            [0, 0, 1, 1, 0],
            [0, 1, 0, 0, 0]]
   output: [[0, 0, 0, 0, 0],
					  [0, 1, 1, 0, 0],
            [0, 1, 0, 1, 0],
            [0, 0, 0, 1, 0],
            [0, 0, 1, 0, 0]]
*/
NO_INLINE void gameOfLife(std::vector<int> const& input, std::vector<int> &output, size_t N) {
std::vector<int> next(input.size(), 0);
  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < N; ++j) {
      int count = 0;
      for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
          if (x == 0 && y == 0) {
            continue;
          }
          size_t r = (i + x + N) % N;
          size_t c = (j + y + N) % N;
          count += input[r * N + c];
        }
      }
      if (input[i * N + j] == 1) {
        next[i * N + j] = (count == 2 || count == 3);
      } else {
        next[i * N + j] = (count == 3);
      }
    }
  }
  output = next;
}