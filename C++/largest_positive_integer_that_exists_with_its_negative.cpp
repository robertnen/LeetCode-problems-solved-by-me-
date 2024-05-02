#include <bits/stdc++.h>

/**
 * Runtime: beats 95.30% of users with C++
 * Memory: beats 79.57% of users with C++
 * Daily problem (Streak 79)
*/

class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        int maxim = -1001, start = 0, end = nums.size() - 1, sum;

        std::sort(nums.begin(), nums.end());

        while(start < end) {
            sum = nums[start] + nums[end];

            if (!sum) {
                maxim = maxim > nums[end] ? maxim : nums[end];
                start++; end--;
            } else if(sum > 0) end--;
                   else start++;
        }

        return maxim != -1001 ? maxim : -1;
    }
};