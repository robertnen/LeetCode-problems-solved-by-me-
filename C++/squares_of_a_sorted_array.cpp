#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        for(auto& i : nums) i *= i;

        std::sort(nums.begin(), nums.end());

        return nums;
    }
};