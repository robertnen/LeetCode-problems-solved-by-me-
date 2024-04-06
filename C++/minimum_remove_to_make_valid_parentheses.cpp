#include <bits/stdc++.h>

/**
 * Runtime: beats 75.33% of users with C++
 * Memory: beats 98.05% of users with C++
 * Daily problem (Streak 53)
*/

class Solution {
public:
    std::string minRemoveToMakeValid(std::string s) {
        int i = 0, num = 0;

        while(s[i]) {
            if(s[i] == '(') num++;
            if(s[i] == ')') {
                if(!num) {
                    s.erase(i, 1);
                    continue;
                } else num--;
            }

            i++;
        }

        i = s.length() - 1;

        while(num > 0) {
            if(s[i] == '(') {
                s.erase(i, 1);
                num--;
                i--;
                continue;
            }
            i--;
        }

        return s;
    }
};