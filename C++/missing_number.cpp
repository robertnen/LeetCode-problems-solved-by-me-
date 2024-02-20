#include <bits/stdc++.h>

/**
 * Runtime: beats 63.35% of users with C++
 * Memory: beats 47.57% of users with C++
 * Daily problem (Streak 7)
*/

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int i, n = nums.size(), s = 0;

        for(i = 0; i < n; i++) s += nums[i];

        return n * (n + 1) / 2 - s;
    }
};