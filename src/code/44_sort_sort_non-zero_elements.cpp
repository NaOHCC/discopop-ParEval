/* Sort the vector x in ascending order ignoring elements with value 0.
   Leave zero valued elements in-place.
   Example:

	 input: [8, 4, 0, 9, 8, 0, 1, -1, 7]
   output: [-1, 1, 0, 4, 7, 0, 8, 8, 9]
*/
NO_INLINE void sortIgnoreZero(std::vector<int> &x) {
int n = x.size();
  int i = 0;
  int j = 0;
  int k = 0;

  while (i < n) {
    if (x[i] == 0) {
      i++;
    } else {
      j = i + 1;
      while (j < n) {
        if (x[j] == 0) {
          j++;
        } else {
          if (x[i] > x[j]) {
            k = x[i];
            x[i] = x[j];
            x[j] = k;
          }
          j++;
        }
      }
      i++;
    }
  }
}