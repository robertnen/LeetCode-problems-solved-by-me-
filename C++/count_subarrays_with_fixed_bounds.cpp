#include <bits/stdc++.h>

/**
 * Runtime: beats 37.50% of users with C++
 * Memory: beats 90.43% of users with C++
 * Daily problem (Streak 47)
*/

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int min_pos, max_pos, start, end, n = nums.size();

        start = end = 0;
        min_pos = max_pos = -1;

        while(end < n) {
            if(!(minK <= nums[end] && nums[end] <= maxK)) {
                start = end++ + 1;
                continue;
            }

            if(nums[end] == minK) min_pos = end;
            if(nums[end] == maxK) max_pos = end;

            ans += std::max(0, std::min(max_pos, min_pos) - start + 1);

            end++;
        }

        return ans;
    }
};