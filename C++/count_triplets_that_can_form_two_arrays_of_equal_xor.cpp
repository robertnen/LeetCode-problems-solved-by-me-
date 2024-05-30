#include <bits/stdc++.h>

/**
 * Runtime: beats 54.79% of users with C++
 * Memory: beats 49.44% of users with C++
 * Daily problem (Streak 107)
*/

class Solution {
public:
    int countTriplets(std::vector<int>& arr) {
        int n = arr.size(), t = 0;
        std::vector<int> dp(n + 1, 0);

        for(int i = 0; i < n; i++) dp[i + 1] = dp[i] ^ arr[i];

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(dp[i] == dp[j + 1]) t += j - i;

        return t;
    }
};