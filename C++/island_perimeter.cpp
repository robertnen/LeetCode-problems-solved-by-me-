#include <bits/stdc++.h>

/**
 * Runtime: beats 42.87% of users with C++
 * Memory: beats 76.64% of users with C++
 * Daily problem (Streak 65)
*/

class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        short total = 0;
        char m = grid.size(), n = grid[0].size();

        for(char i = 0; i < m; i++)
            for(char j = 0; j < n; j++) {
                if(!grid[i][j]) continue;

                total += 4;

                if (i > 0 && grid[i - 1][j]) total -= 2;
                if (j > 0 && grid[i][j - 1]) total -= 2;
            }

        return total;
    }
};