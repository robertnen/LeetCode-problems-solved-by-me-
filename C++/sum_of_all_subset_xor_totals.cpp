#include <bits/stdc++.h>

/**
 * Runtime: beats 100.00% of users with C++
 * Memory: beats 88.36% of users with C++
 * Daily problem (Streak 97)
*/

class Solution {
public:
    int subsetXORSum(std::vector<int>& nums, int level = 0, int curr = 0) {
        if(level == nums.size()) return curr;

        return subsetXORSum(nums, level + 1, curr ^ nums[level]) +
               subsetXORSum(nums, level + 1, curr);
    }
};