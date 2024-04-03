#include <bits/stdc++.h>

/**
 * Runtime: beats 91.87% of users with C++
 * Memory: beats 78.94% of users with C++
 * Daily problem (Streak 50)
*/

class Solution {
private:
    std::vector<std::vector<char>> mat;
    std::string w;
    char n, m, len;
public:
    bool dfs(char i, char j, char step) {
        if(i < 0 || i >= m || j < 0 || j >= n || mat[i][j] != w[step]) return false;
        if(step == len - 1) return true;

        char aux = mat[i][j];
        mat[i][j] = '&';

        step++;
        bool north = dfs(i + 1, j, step),
             east  = dfs(i, j + 1, step),
             south = dfs(i - 1, j, step),
             west  = dfs(i, j - 1, step);

        mat[i][j] = aux;

        return north || east || south || west;
    }

    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        mat.assign(board.begin(), board.end());
        w = word;
        m = board.size();
        n = board[0].size();
        len = word.length();

        for(char i = 0; i < m; i++)
            for(char j = 0; j < n; j++)
                if(dfs(i, j, 0)) return true;

        return false;
    }
};