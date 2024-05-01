#include <bits/stdc++.h>

/**
 * Runtime: beats 42.21% of users with C++
 * Memory: beats 26.16% of users with C++
 * Daily problem (Streak 78)
*/

class Solution {
public:
    std::string reversePrefix(std::string word, char ch) {
        short pos = word.find(ch);

        if (pos != -1)
            reverse(word.begin(), word.begin() + pos + 1);

        return word;
    }
};