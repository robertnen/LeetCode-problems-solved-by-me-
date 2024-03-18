#include <bits/stdc++.h>

/**
 * Runtime: beats 73.13% of users with C++
 * Memory: beats 65.76% of users with C++
 * Daily problem (Streak 34)
*/

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        sort(points.begin(), points.end(), [](const std::vector<int>& arr1, const std::vector<int>& arr2) {
            return arr1[1] < arr2[1];
        });

        int total = 1, endRight = points[0][1];

        for(int i = 0; i < points.size(); i++)
            if(points[i][0] > endRight) {
                total++;
                endRight = points[i][1];
            }

        return total;
    }
};