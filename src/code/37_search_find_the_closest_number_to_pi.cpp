/* Return the index of the value in the vector x that is closest to the math constant PI.
   Use M_PI for the value of PI.
   Example:

   input: [9.18, 3.05, 7.24, 11.3, -166.49, 2.1]
   output: 1
*/
NO_INLINE size_t findClosestToPi(std::vector<double> const& x) {
double min_distance = std::numeric_limits<double>::max();
  size_t min_index = 0;
  for (size_t i = 0; i < x.size(); ++i) {
    double distance = std::abs(x[i] - M_PI);
    if (distance < min_distance) {
      min_distance = distance;
      min_index = i;
    }
  }
  return min_index;
}