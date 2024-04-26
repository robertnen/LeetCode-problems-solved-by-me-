#include <bits/stdc++.h>

/**
 * Runtime: beats 95.32% of users with C++
 * Memory: beats 86.55% of users with C++
 * Daily problem (Streak 73)
*/

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        int n = grid.size(), f_min, s_min, f_pos, s_pos;

        f_min = s_min = 1e9;
        f_pos = s_pos = -1;

        for(int i = 0; i < n; i++) {
            if(i)
                for(int j = 0; j < n; j++)
                        grid[i][j] += (j != f_pos) ? f_min : s_min;

            f_min = s_min = 1e9;

            for(int j = 0; j < n; j++)
                if(grid[i][j] < f_min) {
                    s_min = f_min;
                    f_min = grid[i][j];
                    f_pos = j;
                } else if(grid[i][j] < s_min) {
                    s_min = grid[i][j];
                    s_pos = j;
                }
        }

        return std::min(f_min, s_min);
    }
};