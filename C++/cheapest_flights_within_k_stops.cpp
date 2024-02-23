#include <bits/stdc++.h>
#define INF 1e9

/**
 * Runtime: beats 99.64% of users with C++
 * Memory: beats 34.53% of users with C++
 * Daily problem (Streak 10)
*/

class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
        std::queue<std::pair<int, std::pair<int, int>>> q;
        std::vector<std::pair<int, int>> graph[n];
        std::vector<int> dist(n, INF);

        int stepCounter, node, cost, next, weight;

        for(auto f : flights) graph[f[0]].push_back({f[1] , f[2]});

        q.push({0, {src, 0}});
        dist[src] = 0;

        while(!q.empty()) {
            auto f = q.front();
            stepCounter = f.first;
            node = f.second.first;
            cost = f.second.second;

            q.pop();

            if(k < stepCounter) continue;

            for(auto edge : graph[node]) {
                next = edge.first;
                weight = edge.second;

                if(cost + weight < dist[next] && stepCounter <= k) {
                    dist[next] = cost + weight;
                    q.push({stepCounter + 1, {next, dist[next]}});
                }
            }
        }

        if(dist[dst] == INF) return -1;
        return dist[dst];
    }
};