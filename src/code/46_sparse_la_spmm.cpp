struct COOElement {
   size_t row, column;
   double value;
};

/* Compute the matrix multiplication Y=AX. A is a sparse MxK matrix in COO format.
   X is a sparse KxN matrix in COO format. Y is a dense MxN matrix in row-major.
   Example:

   input: A=[{0,0,-2}, {0,1,1}, {1,1,-1}] X=[{0,1,2}, {1,0,-1}]
   output: Y=[{-1,-4}, {1,0}]
*/
NO_INLINE void spmm(std::vector<COOElement> const& A, std::vector<COOElement> const& X, std::vector<double> &Y, size_t M, size_t K, size_t N) {
std::vector<double> Ytemp(M*N, 0.0);
   for (auto const& a : A) {
      for (auto const& x : X) {
         if (a.column == x.row) {
            Ytemp[a.row*N + x.column] += a.value * x.value;
         }
      }
   }
   Y = std::move(Ytemp);
}