#include <bits/stdc++.h>

/**
 * Runtime: beats 93.93% of users with C++
 * Memory: beats 75.72% of users with C++
 * Daily problem (Streak 92)
*/

class Solution {
public:
    int maximumSafenessFactor(std::vector<std::vector<int>>& grid) {
        int n = grid.size(), nr, nc, safe;

        std::vector<std::vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        std::vector<std::vector<int>> safes(n, std::vector<int>(n, -1));
        std::vector<std::vector<int>> dist(n, std::vector<int>(n, INT_MAX));
        std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
        std::queue<std::pair<int, int>> q;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    dist[r][c] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto& dir : dirs) {
                nr = r + dir[0];
                nc = c + dir[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == INT_MAX) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        pq.push({dist[0][0], {0, 0}});

        safes[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto [d, pos] = pq.top();
            auto [r, c] = pos;

            pq.pop();

            if (r == n - 1 && c == n - 1) return d;

            for (auto& dir : dirs) {
                nr = r + dir[0];
                nc = c + dir[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    safe = std::min(d, dist[nr][nc]);
                    if (safe > safes[nr][nc]) {
                        safes[nr][nc] = safe;
                        pq.push({safe, {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }
};