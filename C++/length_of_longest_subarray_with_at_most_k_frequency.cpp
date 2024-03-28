#include <bits/stdc++.h>

/**
 * Runtime: beats 59.46% of users with C++
 * Memory: beats 12.21% of users with C++
 * Daily problem (Streak 44)
*/


class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        int n = nums.size(), start = 0, end = 0, ans = 0, pos;
        std::unordered_map<int, int> freq;

        while(end < n) {
            pos = nums[end++];
            freq[pos]++;
            while(start < end && freq[pos] > k) freq[nums[start++]]--;

            ans = std::max(ans, end - start);
        }

        return ans;
    }
};