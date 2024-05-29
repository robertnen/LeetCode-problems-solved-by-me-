#include <bits/stdc++.h>

/**
 * Runtime: beats 51.92% of users with C++
 * Memory: beats 76.47% of users with C++
 * Daily problem (Streak 106)
*/

class Solution {
public:
    int numSteps(std::string s) {
        int step = 0;
        bool c = false;

        for(int i = s.length() - 1; i > 0; i--) {
            if (s[i] + c == 49) {
                step += 2;
                c = 1;
            } else step++;
        }

        return step + c;
    }
};
