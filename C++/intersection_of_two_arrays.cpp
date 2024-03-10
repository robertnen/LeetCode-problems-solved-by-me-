#include <bits/stdc++.h>

/**
 * Runtime: beats 68.61% of users with C++
 * Memory: beats 73.82% of users with C++
 * Daily problem (Streak 26)
*/


class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> ans; std::vector<bool> freq(1001, false);

        for(auto num : nums1) freq[num] = true;
        for(auto num : nums2)
            if(freq[num]) {
                ans.push_back(num);
                freq[num] = false;
            }

        return ans;
    }
};