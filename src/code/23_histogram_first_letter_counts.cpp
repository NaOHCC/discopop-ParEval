/* For each letter in the alphabet, count the number of strings in the vector s that start with that letter.
   Assume all strings are in lower case. Store the output in `bins` array.
   Example:

   input: ["dog", "cat", "xray", "cow", "code", "type", "flower"]
   output: [0, 0, 3, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0]
*/
NO_INLINE void firstLetterCounts(std::vector<std::string> const& s, std::array<size_t, 26> &bins) {
for (auto const& str : s) {
        bins[str[0] - 'a']++;
    }
}