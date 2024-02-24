#include <bits/stdc++.h>

/**
 * Runtime: beats 37.30% of users with C++
 * Memory: beats 5.74% of users with C++
 * Daily problem (Streak 11)
*/

class Solution {
public:
    std::vector<int> findAllPeople(int n, std::vector<std::vector<int>>& meetings, int firstPerson) {
        std::map<int, std::vector<std::pair<int, int>>> rooms;
        std::vector<bool> isKeeper(n, false);
        std::vector<int> ret;

        isKeeper[0] = isKeeper[firstPerson] = true;

        for(auto& meeting : meetings)
            rooms[meeting[2]].emplace_back(meeting[0], meeting[1]);

        for(auto& [key, value] : rooms) {
            std::unordered_map<int, std::vector<int>> graph;
            std::unordered_set<int> trusted;
            std::queue<int> q;

            for(auto& [p1, p2] : value) {
                if(isKeeper[p1]) trusted.insert(p1);
                if(isKeeper[p2]) trusted.insert(p2);
                graph[p1].push_back(p2);
                graph[p2].push_back(p1);
            }

            for(auto& person : trusted) q.push(person);

            while(q.size()) {
                auto p1 = q.front(); q.pop();
                for(auto& p2 : graph[p1])
                    if(!isKeeper[p2]) {isKeeper[p2] = true; q.push(p2);}
            }
        }

        for(int i = 0; i < n; i++)
            if(isKeeper[i]) ret.push_back(i);

        return ret;
    }
};