#include <numeric>
#include <vector>

/* Compute the reverse prefix sum of the vector x into output.
   Examples:

   input: [1, 7, 4, 6, 6, 2]
   output: [2, 8, 14, 18, 25, 26]

   input: [3, 3, 7, 1, -2]
   output: [-2, -1, 6, 9, 12]
*/

void NO_INLINE reversePrefixSum(std::vector<int> const& x, std::vector<int>& output) {
    std::vector<int> reverseX;

    for (int i = x.size() - 1; i >= 0; i--) {
        reverseX.push_back(x[i]);
    }

    if (!reverseX.empty()) {
        output[0] = reverseX[0]; 
        for (size_t i = 1; i < reverseX.size(); i++) {
            output[i] = output[i - 1] + reverseX[i]; 
        }
    }
}