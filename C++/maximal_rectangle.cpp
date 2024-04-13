#include <bits/stdc++.h>

/**
 * Runtime: beats 84.46% of users with C++
 * Memory: beats 87.72% of users with C++
 * Daily problem (Streak 60)
*/

class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& mat) {
        int rows = mat.size(), cols = mat[0].size(), ans = 0, height, width;
        std::vector<int> heights(cols + 1, 0);

        for(const auto& row : mat) {
            for(int i = 0; i < cols; i++) {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }

            std::stack<int> s;

            for(int i = 0; i < heights.size(); i++) {
                while(!s.empty() && heights[i] < heights[s.top()]) {
                    height = heights[s.top()];
                    s.pop();

                    width = s.empty() ? i : i - s.top() - 1;
                    ans = std::max(ans, height * width);
                }
                s.push(i);
            }
        }

        return ans;
    }
};