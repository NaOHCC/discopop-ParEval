/* Count the number of doubles in the vector x that have a fractional part 
   in [0, 0.25), [0.25, 0.5), [0.5, 0.75), and [0.75, 1). Store the counts in `bins`.
   Examples:

   input: [7.8, 4.2, 9.1, 7.6, 0.27, 1.5, 3.8]
   output: [2, 1, 2, 2]

   input: [1.9, 0.2, 0.6, 10.1, 7.4]
   output: [2, 1, 1, 1]
*/
NO_INLINE void countQuartiles(std::vector<double> const& x, std::array<size_t, 4> &bins) {
for (double num : x) {
        double fractional_part = num - std::floor(num);
        if (fractional_part < 0.25) {
            bins[0]++;
        } else if (fractional_part < 0.5) {
            bins[1]++;
        } else if (fractional_part < 0.75) {
            bins[2]++;
        } else {
            bins[3]++;
        }
    }
}