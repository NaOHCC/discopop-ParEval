/* Return true if `val` is only in one of vectors x or y.
   Return false if it is in both or neither.
   Examples:

   input: x=[1,8,4,3,2], y=[3,4,4,1,1,7], val=7
   output: true

   input: x=[1,8,4,3,2], y=[3,4,4,1,1,7], val=1
   output: false
*/
NO_INLINE bool xorContains(std::vector<int> const& x, std::vector<int> const& y, int val) {
return std::find(x.begin(), x.end(), val)!= x.end() ^ std::find(y.begin(), y.end(), val)!= y.end();
}