#include <bits/stdc++.h>

/**
 * Runtime: beats 86.83% of users with C++
 * Memory: beats 64.67% of users with C++
 * Daily problem (Streak 77)
*/

class Solution {
public:
    long long wonderfulSubstrings(std::string word) {
        std::vector<long long> x_set(1024, 0);
        long long ans = 0;
        int pref = 0, pos;

        x_set[0] = 1;

        for(char ch : word) {
            pos = ch - 'a';
            pref ^= 1 << pos;
            ans += x_set[pref];

            for(char i = 0; i < 10; i++) ans += x_set[pref ^ (1 << i)];

            x_set[pref]++;
        }

        return ans;
    }
};
