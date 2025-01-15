/* Return the average of the vector x.
   Examples:
		
	 input: [1, 8, 4, 5, 1]
   output: 3.8

   input: [2, 2, 2, 3]
   output: 2.25
*/
NO_INLINE double average(std::vector<double> const& x) {
double sum = 0;
	for (double i : x) {
		sum += i;
	}
	return sum / x.size();
}