#include <bits/stdc++.h>

/**
 * Runtime: beats 100% of users with C++
 * Memory: beats 92.84% of users with C++
 * Daily problem (Streak 54)
*/

class Solution {
public:
    bool checkValidString(std::string s) {
        char i = 0, num_left = 0, num_s = 0;

        while(s[i]) {
            if(s[i] == '(') {
                num_left++;
                num_s++;
            } else if(s[i] == ')') {
                num_left--;
                num_s--;
            } else {
                num_left--;
                num_s++;
            }

            i++;
            if(num_s < 0) return false;
            if(num_left < 0) num_left = 0;
        }

        return num_left == 0;
    }
};