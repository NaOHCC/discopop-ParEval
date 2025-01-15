struct Point {
	double x, y;
};

double triangleArea(Point const& A, Point const& B, Point const& C) {
  return 0.5 * std::abs( A.x*(B.y-C.y) + B.x*(C.y-A.y) + C.x*(A.y-B.y) );
}

/* Return the area of the smallest triangle that can be formed by any 3 points.
   Example:

   input: [{0, 10}, {5, 5}, {1,0}, {-1, 1}, {-10, 0}]
   output: 5.5
*/
NO_INLINE double smallestArea(std::vector<Point> const& points) {
double minArea = std::numeric_limits<double>::max();
  for (int i = 0; i < points.size(); ++i) {
    for (int j = i + 1; j < points.size(); ++j) {
      for (int k = j + 1; k < points.size(); ++k) {
        double area = triangleArea(points[i], points[j], points[k]);
        if (area < minArea) {
          minArea = area;
        }
      }
    }
  }
  return minArea;
}