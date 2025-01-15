/* Return the logical XOR reduction of the vector of bools x.
   Example:

   input: [false, false, false, true]
   output: true
*/
NO_INLINE bool reduceLogicalXOR(std::vector<bool> const& x) {
bool result = false;
  for (auto const& i : x) {
    result ^= i;
  }
  return result;
}