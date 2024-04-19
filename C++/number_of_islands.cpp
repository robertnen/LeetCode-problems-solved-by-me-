#include <bits/stdc++.h>

/**
 * Runtime: beats 90.21% of users with C++
 * Memory: beats 81.51% of users with C++
 * Daily problem (Streak 66)
*/

class Solution {
public:
    void dfs(short i, short j, std::vector<std::vector<char>>& grid) {
        if(i < 0 || j < 0
           || i >= grid.size()
           || j >= grid[0].size()
           || grid[i][j] == '0') return;

        grid[i][j] = '0';

        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
        short m = grid.size(), n = grid[0].size(), ans = 0;

        for(short i = 0; i < m; i++)
            for(short j = 0; j < n; j++)
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid);
                }

        return ans;
    }
};