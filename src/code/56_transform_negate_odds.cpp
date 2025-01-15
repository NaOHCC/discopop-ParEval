/* In the vector x negate the odd values and divide the even values by 2.
   Example:

   input: [16, 11, 12, 14, 1, 0, 5]
   output: [8, -11, 6, 7, -1, 0, -5]
*/
NO_INLINE void negateOddsAndHalveEvens(std::vector<int> &x) {
for (int i = 0; i < x.size(); i++) {
        if (x[i] % 2 == 0) {
            x[i] /= 2;
        } else {
            x[i] = -x[i];
        }
    }
}