/* Find the k-th smallest element of the vector x.
   Example:
   
   input: x=[1, 7, 6, 0, 2, 2, 10, 6], k=4
   output: 6
*/
NO_INLINE int findKthSmallest(std::vector<int> const& x, int k) {
int n = x.size();
    std::vector<int> y(x);
    std::sort(y.begin(), y.end());
    return y[k-1];
}