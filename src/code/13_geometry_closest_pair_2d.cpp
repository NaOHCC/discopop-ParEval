struct Point {
	double x, y;
};

double distance(Point const& p1, Point const& p2) {
	return std::sqrt(std::pow(p2.x-p1.x, 2) + std::pow(p2.y-p1.y, 2));
}

/* Return the distance between the closest two points in the vector points.
   Example: 

   input: [{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}]
   output: 1.41421
*/
NO_INLINE double closestPair(std::vector<Point> const& points) {
if (points.size() < 2) {
		return 0;
	}
	double min_dist = std::numeric_limits<double>::max();
	for (int i = 0; i < points.size(); ++i) {
		for (int j = i + 1; j < points.size(); ++j) {
			double dist = distance(points[i], points[j]);
			if (dist < min_dist) {
				min_dist = dist;
			}
		}
	}
	return min_dist;
}