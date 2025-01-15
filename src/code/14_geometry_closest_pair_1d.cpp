double distance(double x1, double x2) {
	return std::abs(x1 - x2);
}

/* Return the distance between the closest two elements in the vector x.
   Example: 

   input: [7, 3, 9, 12, 31, 1]
   output: 2
*/
NO_INLINE double closestPair(std::vector<double> const& x) {
double min_dist = std::numeric_limits<double>::max();
	for (size_t i = 0; i < x.size(); ++i) {
		for (size_t j = i + 1; j < x.size(); ++j) {
			double dist = distance(x[i], x[j]);
			if (dist < min_dist) {
				min_dist = dist;
			}
		}
	}
	return min_dist;
}