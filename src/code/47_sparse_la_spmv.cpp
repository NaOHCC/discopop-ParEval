struct COOElement {
   size_t row, column;
   double value;
};

/* Compute y = alpha*A*x + beta*y where alpha and beta are scalars, x and y are vectors,
   and A is a sparse matrix stored in COO format.
   A has dimensions MxN, x has N values, and y has M values.
   Example:

   input: alpha=0.5 beta=1.0 A=[{0,1,3}, {1,0,-1}] x=[-4, 2] y=[-1,1]
   output: y=[2, 3]
*/
NO_INLINE void spmv(double alpha, std::vector<COOElement> const& A, std::vector<double> const& x, double beta, std::vector<double> &y, size_t M, size_t N) {
for (size_t i = 0; i < M; ++i) {
      y[i] *= beta;
   }

   for (size_t i = 0; i < A.size(); ++i) {
      y[A[i].row] += alpha * A[i].value * x[A[i].column];
   }
}