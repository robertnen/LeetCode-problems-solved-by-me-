
/**
 * Runtime: beats 100% of users with C++
 * Memory: beats 39.77% of users with C++
 * Daily problem (Streak 6)
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (long long) n && !((long long) n & ((long long) n - 1));
    }
};