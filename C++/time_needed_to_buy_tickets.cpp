#include <bits/stdc++.h>

/**
 * Runtime: beats 100% of users with C++
 * Memory: beats 46.11% of users with C++
 * Daily problem (Streak 56)
*/

class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        int time = 0;
        char i, n = tickets.size();

        for(i = 0; i < n; i++)
            if(i <= k) time += std::min(tickets[i], tickets[k]);
            else time += std::min(tickets[i], tickets[k] - 1);

        return time;
    }
};