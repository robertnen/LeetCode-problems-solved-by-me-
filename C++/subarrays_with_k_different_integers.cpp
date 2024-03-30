#include <bits/stdc++.h>

/**
 * Runtime: beats 93.16% of users with C++
 * Memory: beats 95.76% of users with C++
 * Daily problem (Streak 46)
*/

class Solution {
public:
    int subarrAtMostK(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> freq(n + 1, 0);
        int start = 0, end = 0, ans = 0;

        for(; end < n; ++end) {
            if(!freq[nums[end]]++) k--;

            while(k == -1)
                if(freq[nums[start++]]-- == 1) k++;

            ans += end - start + 1;
        }

        return ans;
    }

    int subarraysWithKDistinct(std::vector<int>& nums, int k) {
        return subarrAtMostK(nums, k) - subarrAtMostK(nums, k - 1);
    }
};