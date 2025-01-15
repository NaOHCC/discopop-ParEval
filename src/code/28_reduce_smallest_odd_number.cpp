/* Return the value of the smallest odd number in the vector x.
   Examples:

   input: [7, 9, 5, 2, 8, 16, 4, 1]
   output: 1

   input: [8, 36, 7, 2, 11]
   output: 7
*/
NO_INLINE int smallestOdd(std::vector<int> const& x) {
int smallest = x[0];
  for (int i = 1; i < x.size(); i++) {
    if (x[i] % 2 == 1 && x[i] < smallest) {
      smallest = x[i];
    }
  }
  return smallest;
}