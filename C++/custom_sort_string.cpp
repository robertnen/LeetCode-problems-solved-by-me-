#include <bits/stdc++.h>

/**
 * Runtime: beats 100% of users with C++
 * Memory: beats 26.14% of users with C++
 * Daily problem (Streak 27)
*/

class Solution {
private:
    int alphaValues[26];
public:
    std::string customSortString(std::string order, std::string s) {
        int len = order.length();
        std::vector<char> toSort;

        for(int i = 0; i < 26; i++) alphaValues[i] = 27;
        for(int i = 0; i < len; i++) alphaValues[order[i] - 'a'] = i;

        toSort.insert(toSort.end(), s.begin(), s.end());

        std::sort(toSort.begin(), toSort.end(), [&](char a, char b) {
            return alphaValues[a - 'a'] < alphaValues[b - 'a'];
        });

        s.assign(toSort.begin(), toSort.end());

        return s;
    }
};