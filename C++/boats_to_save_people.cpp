#include <bits/stdc++.h>

/**
 * Runtime: beats 93.77% of users with C++
 * Memory: beats 85.44% of users with C++
 * Daily problem (Streak 81)
*/

class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());

        int ans = 0, n = people.size() - 1;

        for(int i = 0; i <= n; n--) {
            ans++;
            if (people[i] <= limit - people[n]) i++;
        }

        return ans;
    }
};