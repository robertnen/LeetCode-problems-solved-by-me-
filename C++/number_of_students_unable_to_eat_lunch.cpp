#include <bits/stdc++.h>

/**
 * Runtime: beats 100% of users with C++
 * Memory: beats 79.46% of users with C++
 * Daily problem (Streak 55)
*/

class Solution {
public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
        char n = students.size(), counters[2] = {0, 0}, stud = 0;

        for(; stud < n; stud++)
            if(!students[stud]) counters[0]++;

        counters[1] = n - counters[0];

        for(char sand : sandwiches) {
            if(!counters[sand]) return counters[1 - sand];
            counters[sand]--;
        }

        return 0;
    }
};