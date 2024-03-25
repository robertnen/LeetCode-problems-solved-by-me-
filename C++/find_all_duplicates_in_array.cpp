#include <bits/stdc++.h>

/**
 * Runtime: beats 37.30% of users with C++
 * Memory: beats 5.74% of users with C++
 * Daily problem (Streak 11)
*/

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> ans;
        bool *exists = (bool *) calloc(nums.size() + 1, sizeof(bool));

        for(int num : nums) {
            if(exists[num]) ans.push_back(num);
            exists[num] = true;
        }

        free(exists);

        return ans;
    }
};