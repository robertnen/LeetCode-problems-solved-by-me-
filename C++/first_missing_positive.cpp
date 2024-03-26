#include <bits/stdc++.h>

/**
 * Runtime: beats 71.13% of users with C++
 * Memory: beats 55.21% of users with C++
 * Daily problem (Streak 42)
*/

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size(), m = n + 1;

        for(int i = 0; i < n; i++)
            if(!(nums[i] > 0 && nums[i] < m)) nums[i] = m;

        for(int i = 0; i < n; i++) {
            m = abs(nums[i]);

            if(m-- > n) continue;
            if(nums[m] > 0) nums[m] = -nums[m];
        }

        for(int i = 0; i < n; i++)
            if(nums[i] >= 0) return i + 1;

        return n + 1;
    }
};