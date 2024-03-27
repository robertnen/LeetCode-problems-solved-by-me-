#include <bits/stdc++.h>

/**
 * Runtime: beats 29.61% of users with C++
 * Memory: beats 57.48% of users with C++
 * Daily problem (Streak 43)
*/

class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        if(!k) return k;

        int n = nums.size(), counter = 0, left = 0, right = 0, p = 1;

        while(right < n) {
            p *= nums[right++];
            while(left < right && p >= k) p /= nums[left++];

            counter += (right - left);
        }

        return counter;
    }
};