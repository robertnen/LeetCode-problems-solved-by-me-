#include <bits/stdc++.h>

/**
 * Runtime: beats 76.72% of users with C++
 * Memory: beats 87.96% of users with C++
 * Daily problem (Streak 70)
*/

class Solution {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        if(n == 1) return {0};

        std::queue<int> q;
        std::vector<int> deg(n, 0), ans;
        std::vector<std::vector<int>> mat(n);

        int x, y, qs, center;

        for(auto& edge : edges) {
            x = edge[0]; y = edge[1];

            mat[x].push_back(y);
            mat[y].push_back(x);

            deg[x]++; deg[y]++;
        }

        for(int i = 0; i < n; i++)
            if(deg[i] == 1) q.push(i);

        center = n;

        while(!q.empty()) {
            qs = q.size();
            center -= qs;

            for(int i = 0; i < qs; i++) {
                x = q.front();
                q.pop();

                if(!center) ans.push_back(x);

                for(int y : mat[x])
                    if(deg[y]-- == 2) q.push(y);
            }
        }

        return ans;
    }
};