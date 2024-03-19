#include <bits/stdc++.h>
#include <bits/range_access.h>
#include <bits/valarray_array.h>

/**
 * Runtime: beats 94.96% of users with C++
 * Memory: beats 298.52% of users with C++
 * Daily problem (Streak 35)
*/

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        short freq[26] = {0};

        for(auto ch : tasks) freq[ch - 'A']++;

        std::sort(begin(freq), end(freq));

        short cycle = freq[25] - 1;
        int slice = cycle * n;

        for(char i = 24; i > -1; i--) slice -= std::min(freq[i], cycle);

        return tasks.size() + (slice < 0 ? 0 : slice);
    }
};