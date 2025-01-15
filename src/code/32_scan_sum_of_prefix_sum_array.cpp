/* Compute the prefix sum array of the vector x and return its sum.
   Example:

   input: [-7, 2, 1, 9, 4, 8]
   output: 15
*/
NO_INLINE double sumOfPrefixSum(std::vector<double> const& x) {
double sum = 0;
    std::vector<double> prefix_sum(x.size());

    for (size_t i = 0; i < x.size(); ++i) {
        if (i == 0) {
            prefix_sum[i] = x[i];
        } else {
            prefix_sum[i] = prefix_sum[i - 1] + x[i];
        }
        sum += prefix_sum[i];
    }

    return sum;
}