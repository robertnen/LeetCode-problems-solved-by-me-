/**
 * Runtime: beats 100% of users with Java
 * Memory: beats 7.46% of users with Java
 * Daily problem (Streak 8)
*/

class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        byte counter = 0;
        while(left < right) {
            left >>= 1;
            right >>= 1;
            counter++;
        }

        return left << counter;
    }
}