#include <bits/stdc++.h>

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int k) {
        int maxim = -1, n = nums.size(), start = 0, end = 0;
        long long ans = 0;

        for(int num : nums) if(maxim < num) maxim = num;

        while(end < n) {
            if(nums[end++] == maxim) k--;

            while(!k)
                if(nums[start++] == maxim) k++;

            ans += start;
        }

        return ans;
    }
};