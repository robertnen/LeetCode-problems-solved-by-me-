/**
 * Runtime: beats 100% of users with C++
 * Memory: beats 41.86% of users with C++
 * Daily problem (Streak 29)
*/

class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1) return 1;
        if(n == 3) return -1;

        short x = n / 2 + 2, y;

        while(x <= n) {
            y = n - x;
            if((2 * x * y) % (x - y - 1) == 0 && (2 * x * y) / (x - y - 1) == n) return x;
            x++;
        }

        return -1;
    }
};