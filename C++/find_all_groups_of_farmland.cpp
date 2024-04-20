#include <bits/stdc++.h>

/**
 * Runtime: beats 99.64% of users with C++
 * Memory: beats 97.82% of users with C++
 * Daily problem (Streak 67)
*/

class Solution {
public:
    std::vector<std::vector<int>> findFarmland(std::vector<std::vector<int>>& land) {
        int m = land.size(), n = land[0].size(), row, col;
        std::vector<std::vector<int>> ans;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(land[i][j] && (!i || !land[i - 1][j]) && (!j || !land[i][j - 1])) {
                    row = i; col = j;

                    while(row + 1 < m && land[row + 1][j]) row++;
                    while(col + 1 < n && land[i][col + 1]) col++;

                    ans.push_back({i, j, row, col});
                }

        return ans;
    }
};