#include <bits/stdc++.h>

/**
 * Runtime: beats 31.84% of users with C++
 * Memory: beats 37.53% of users with C++
 * Daily problem (Streak 90)
*/

class Solution {
public:
    int matrixScore(std::vector<std::vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), ans, aux, togNum;

        ans = (1 << (col - 1)) * row;

        for(int c = 1; c < col; c++) {
            togNum = 0;
            aux = 1 << (col - 1 - c);

            for(int r = 0; r < row; r++)
                if(grid[r][c] == grid[r][0]) togNum++;

            ans += std::max(row - togNum, togNum) * aux;
        }

        return ans;
    }
};