#include <bits/stdc++.h>

/**
 * Runtime: beats 47.78% of users with C++
 * Memory: beats 81.15% of users with C++
 * Daily problem (Streak 98)
*/

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans = {{}};

        for (auto x : nums) {
            int size = ans.size();
            for (int i = 0; i < size; i++) {
                std::vector<int> s = ans[i];

                s.push_back(x);
                ans.push_back(s);
            }
        }
        return ans;
    }
};