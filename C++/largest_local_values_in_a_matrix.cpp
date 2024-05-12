#include <bits/stdc++.h>

/**
 * Runtime: beats 53.93% of users with C++
 * Memory: beats 53.31% of users with C++
 * Daily problem (Streak 89)
*/

class Solution {
public:
    std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid) {
        int n = grid.size(), aux;

        for(int i = 1; i < n - 1; i++)
            for(int j = 1; j < n - 1; j++) {
                aux = 0;

                for(int k = i - 1; k <= i + 1; k++)
                    for(int l = j - 1; l <= j + 1; l++)
                        if(aux < grid[k][l]) aux = grid[k][l];

                grid[i - 1][j - 1] = aux;
            }

        grid.resize(n - 2);
        for(int i = 0; i < grid.size(); i++) grid[i].resize(n - 2);

        return grid;
    }
};
