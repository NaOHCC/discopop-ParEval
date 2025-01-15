/* Replace every element of x with the square of its value.
   Example:

   input: [5, 1, 2, -4, 8]
   output: [25, 1, 4, 16, 64]
*/
NO_INLINE void squareEach(std::vector<int> &x) {
for (int i = 0; i < x.size(); i++) {
        x[i] = x[i] * x[i];
    }
}