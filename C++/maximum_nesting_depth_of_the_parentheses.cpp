#include <bits/stdc++.h>

/**
 * Runtime: beats 40.00% of users with C++
 * Memory: beats 49.50% of users with C++
 * Daily problem (Streak 51)
*/

class Solution {
public:
    int maxDepth(std::string s) {
        char len = 0, max_len = 0, n = s.length();

        for(char i = 0; i < n; i++) {
            switch(s[i]) {
                case ')':
                    if(len > max_len) max_len = len;
                    len--;
                    break;
                case '(':
                    len++;
                    break;
                default:
                    break;
            }
        }

        return max_len;
    }
};