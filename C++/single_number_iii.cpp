#include <bits/stdc++.h>

/**
 * Runtime: beats 8.69% of users with C++
 * Memory: beats 10.01% of users with C++
 * Daily problem (Streak 108)
*/

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        std::vector<int> ans;

        for(int n : nums) freq[n]++;
        for(auto [id, f] : freq) if(f == 1) ans.push_back(id);

        return ans;
    }
};