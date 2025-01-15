/* Compute the ReLU function on every element of x. Elements less than zero become zero,
   while elements greater than zero stay the same.
   Example:

   input: [-1.8, 24.0, 1.2, 0.0, -5.1, -0.2, 4.5]
   output: [0, 24.0, 1.2, 0, 0, 0, 4.5]
*/
NO_INLINE void relu(std::vector<double> &x) {
for (int i = 0; i < x.size(); i++) {
        if (x[i] < 0) {
            x[i] = 0;
        }
    }
}