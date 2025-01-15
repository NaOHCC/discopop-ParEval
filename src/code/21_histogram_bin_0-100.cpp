/* Vector x contains values between 0 and 100, inclusive. Count the number of
   values in [0,10), [10, 20), [20, 30), ... and store the counts in `bins`.
   Example:

   input: [7, 32, 95, 12, 39, 32, 11, 71, 70, 66]
   output: [1, 2, 0, 3, 0, 0, 1, 2, 0, 1]
*/
NO_INLINE void binsBy10Count(std::vector<double> const& x, std::array<size_t, 10> &bins) {
for (auto const& value : x) {
    if (value < 10) {
      bins[0]++;
    } else if (value < 20) {
      bins[1]++;
    } else if (value < 30) {
      bins[2]++;
    } else if (value < 40) {
      bins[3]++;
    } else if (value < 50) {
      bins[4]++;
    } else if (value < 60) {
      bins[5]++;
    } else if (value < 70) {
      bins[6]++;
    } else if (value < 80) {
      bins[7]++;
    } else if (value < 90) {
      bins[8]++;
    } else {
      bins[9]++;
    }
  }
}