#include <bits/stdc++.h>

/**
 * Runtime: beats 92.74% of users with C++
 * Memory: beats 38.83% of users with C++
 * Daily problem (Streak 88)
*/

class Solution {
public:
    double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
        int n = quality.size(), now;
        double rat = 0, ratio = 0, minim = DBL_MAX;

        std::vector<std::pair<double, int>> quaRatio;
        std::priority_queue<int> goods;

        for(int i = 0; i < n; i++)
            quaRatio.emplace_back((1. * wage[i]) / quality[i], quality[i]);

        std::sort(quaRatio.begin(), quaRatio.end());

        for(int i = 0; i < n; i++) {
            rat = quaRatio[i].first;
            now = quaRatio[i].second;

            goods.push(now);
            ratio += now;

            if(goods.size() > k) {
                ratio -= goods.top();
                goods.pop();
            }

            if(goods.size() == k && minim > ratio * rat)
                minim = ratio * rat;
        }
        return minim;
    }
};