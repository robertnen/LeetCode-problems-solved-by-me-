#include <bits/stdc++.h>

/**
 * Runtime: beats 98.91% of users with C++
 * Memory: beats 63.03% of users with C++
 * Daily problem (Streak 4)
*/

class Solution {
public:
    int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pqueue;

        int diff, i, n = heights.size();

        for(i = 0; i < n - 1; i++) {
            diff = heights[i + 1] - heights[i];

            if(diff < 0) continue;

            pqueue.push(diff);

            if(pqueue.size() <= ladders) continue;

            diff = pqueue.top();
            pqueue.pop();

            if(diff > bricks) return i;
            else bricks -= diff;
        }

        return n - 1;
    }
};