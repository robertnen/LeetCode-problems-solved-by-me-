#include <bits/stdc++.h>

/**
 * Runtime: beats 100.00% of users with C++
 * Memory: beats 89.71% of users with C++
 * Daily problem (Streak 52)
*/

class Solution {
public:
    std::string makeGood(std::string s) {
        char i = 1, ch = s.length();

        if(ch < 2) return s;

        ch = s[0];

        while(s[i]) {
            if(std::abs(ch - s[i]) == 32) {
                s.erase(i - 1, 2);
                ch = s[0];
                i = 1;
                continue;
            }
            ch = s[i++];
        }

        return s;
    }
};