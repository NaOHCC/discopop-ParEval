/* Compute the prefix sum of the vector x into output.
   Example:
   
   input: [1, 7, 4, 6, 6, 2]
   output: [1, 8, 12, 18, 24, 26]
*/
NO_INLINE void prefixSum(std::vector<double> const& x, std::vector<double> &output) {
output.resize(x.size());
  output[0] = x[0];
  for (int i = 1; i < x.size(); ++i) {
    output[i] = output[i-1] + x[i];
  }
}