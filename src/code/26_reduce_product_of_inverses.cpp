/* Return the product of the vector x with every odd indexed element inverted.
   i.e. x_0 * 1/x_1 * x_2 * 1/x_3 * x_4 ...
   Example:

   input: [4, 2, 10, 4, 5]
   output: 25
*/
NO_INLINE double productWithInverses(std::vector<double> const& x) {
double result = 1;
  for (int i = 0; i < x.size(); i++) {
    if (i % 2 == 0) {
      result *= x[i];
    } else {
      result *= 1 / x[i];
    }
  }
  return result;
}