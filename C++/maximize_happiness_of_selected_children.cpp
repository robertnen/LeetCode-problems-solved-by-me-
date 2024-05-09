#include <bits/stdc++.h>

/**
 * Runtime: beats 98.58% of users with C++
 * Memory: beats 60.15% of users with C++
 * Daily problem (Streak 86)
*/

class Solution {
public:
    long long maximumHappinessSum(std::vector<int>& happiness, int k) {
        int i = 0;
        long long ans = 0;

        std::sort(happiness.begin(), happiness.end(), std::greater<int>());

        while(k--) {
            happiness[i] = std::max(happiness[i] - i, 0);
            ans += happiness[i++];
        }

        return ans;
    }
};