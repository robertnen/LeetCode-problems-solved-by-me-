#include <bits/stdc++.h>

/**
 * Runtime: beats 74.21% of users with C++
 * Memory: beats 81.32% of users with C++
 * Daily problem (Streak 91)
*/

class Solution {
private:
    int dirX[4] = {1, -1, 0, 0}, dirY[4] = {0, 0, -1, 1}, row, col;
public:
    int alee(std::vector<std::vector<int>>& grid, int r, int c) {
        if(r < 0 || r >= row) return 0;
        if(c < 0 || c >= col) return 0;
        if(!grid[r][c]) return 0;

        int now, local;

        local = now = grid[r][c];
        grid[r][c] = 0;

        for(int i = 0; i < 4; i++)
            local = std::max(local, now + alee(grid, r + dirX[i], c + dirY[i]));


        grid[r][c] = now;
        return local;
    }

    int getMaximumGold(std::vector<std::vector<int>>& grid) {
        int maxim = 0;

        row = grid.size();
        col = grid[0].size();

        for(int r = 0; r < row; r++)
            for(int c = 0; c < col; c++)
                if(grid[r][c])
                    maxim = std::max(maxim, alee(grid, r, c));

        return maxim;
    }
};