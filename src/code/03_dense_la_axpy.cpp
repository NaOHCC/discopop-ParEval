/* Compute z = alpha*x+y where x and y are vectors. Store the result in z.
   Example:
   
   input: x=[1, -5, 2, 9] y=[0, 4, 1, -1] alpha=2
   output: z=[2, -6, 5, 17]
*/
NO_INLINE void axpy(double alpha, std::vector<double> const& x, std::vector<double> const& y, std::vector<double> &z) {
for (int i = 0; i < x.size(); ++i) {
    z[i] = alpha*x[i] + y[i];
  }
}