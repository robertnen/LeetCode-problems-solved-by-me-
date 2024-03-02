#include <bits/stdc++.h>

/**
 * Runtime: beats 43.10% of users with C++
 * Memory: beats 28.90% of users with C++
 * Daily problem (Streak 18)
*/

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        for(auto& i : nums) i *= i;

        std::sort(nums.begin(), nums.end());

        return nums;
    }
};