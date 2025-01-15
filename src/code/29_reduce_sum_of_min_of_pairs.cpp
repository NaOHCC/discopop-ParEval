/* Return the sum of the minimum value at each index of vectors x and y for all indices.
   i.e. sum = min(x_0, y_0) + min(x_1, y_1) + min(x_2, y_2) + ...
   Example:

   input: x=[3, 4, 0, 2, 3], y=[2, 5, 3, 1, 7]
   output: 10
*/
NO_INLINE double sumOfMinimumElements(std::vector<double> const& x, std::vector<double> const& y) {
double sum = 0;
  for (int i = 0; i < x.size(); i++) {
    sum += std::min(x[i], y[i]);
  }
  return sum;
}