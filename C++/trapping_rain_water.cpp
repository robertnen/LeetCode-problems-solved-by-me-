#include <bits/stdc++.h>

/**
 * Runtime: beats 93.97% of users with C++
 * Memory: beats 95.63% of users with C++
 * Daily problem (Streak 59)
*/

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size() - 1, prev = height[0], next = height[n];
        int ans = 0, i = 0;

        while(i < n)
            if(prev <= next) {
                ans += prev - height[i++];
                prev = std::max(prev, height[i]);
            } else {
                ans += next - height[n--];
                next = std::max(next, height[n]);
            }

        return ans;
    }
};