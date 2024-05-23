#include <bits/stdc++.h>

/**
 * Runtime: beats 5.17% of users with C++
 * Memory: beats 5.17% of users with C++
 * Daily problem (Streak 100)
*/

class Solution {
public:
    int beautifulSubsets(std::vector<int>& nums, int k) {
        q = k;
        total = 0;

        search(0, nums);
        return total - 1;
    }

private:
    int total, q;
    std::unordered_map<int, int> isVisited;

    void search(int idx, std::vector<int>& nums) {
        if(idx == nums.size()) {total++; return;}

        int num = nums[idx];

        if (isVisited.find(num - q) == isVisited.end() &&
            isVisited.find(num + q) == isVisited.end()) {
                isVisited[num]++;

                search(idx + 1, nums);

                isVisited[num]--;

                if (!isVisited[num]) isVisited.erase(num);
            }

        search(idx + 1, nums);
    }
};