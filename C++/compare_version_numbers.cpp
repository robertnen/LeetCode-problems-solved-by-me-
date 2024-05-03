#include <bits/stdc++.h>

/**
 * Runtime: beats 100% of users with C++
 * Memory: beats 77.28% of users with C++
 * Daily problem (Streak 80)
*/

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        int s1 = version1.size(), s2 = version2.size();
        long x, y;

        x = y = 0;

        for(int i = 0, j = 0; i < s1 || j < s2; i++, j++) {
            while(i < s1 && version1[i] != '.')
                x = 10 * x + version1[i++] - '0';

            while(j < s2 && version2[j] != '.')
                y = 10 * y + version2[j++] - '0';

            if(x < y) return -1;
            else if(x > y) return 1;

            x = y = 0;
        }

        return 0;
    }
};