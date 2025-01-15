/* For each value in the vector x compute its index in the sorted vector.
   Store the results in `ranks`.
   Examples:

   input: [3.1, 2.8, 9.1, 0.4, 3.14]
   output: [2, 1, 4, 0, 3]
 
   input: [100, 7.6, 16.1, 18, 7.6]
   output: [4, 0, 1, 2, 3]
*/
NO_INLINE void ranks(std::vector<float> const& x, std::vector<size_t> &ranks) {
std::vector<float> sorted = x;
    std::sort(sorted.begin(), sorted.end());
    ranks.resize(x.size());
    for (size_t i = 0; i < x.size(); ++i) {
        ranks[i] = std::distance(sorted.begin(), std::lower_bound(sorted.begin(), sorted.end(), x[i]));
    }
}