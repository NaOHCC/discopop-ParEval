/* Replace the i-th element of the vector x with the minimum value from indices 0 through i.
   Examples:

   input: [8, 6, -1, 7, 3, 4, 4]
   output: [8, 6, -1, -1, -1, -1, -1]

   input: [5, 4, 6, 4, 3, 6, 1, 1]
   output: [5, 4, 4, 4, 3, 3, 1, 1]
*/
NO_INLINE void partialMinimums(std::vector<float> &x) {
float min = x[0];
    for (int i = 0; i < x.size(); i++) {
        if (x[i] < min) {
            min = x[i];
        }
        x[i] = min;
    }
}