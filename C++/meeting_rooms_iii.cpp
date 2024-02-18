#include <bits/stdc++.h>
#define INFINITY 1e18

/**
 * Runtime: beats 79.94% of users with C++
 * Memory: beats 69.91% of users with C++
 * Daily problem (Streak 5)
*/

class Solution {
public:
    int mostBooked(int n, std::vector<std::vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        std::vector<int> dCnt(n, 0); std::vector<long long> cnt(n, 0);
        int i, j, minPos, maxPos, start, end, size = meetings.size();
        long long maxCnt;
        bool flag;

        for(i = 0; i < size; i++) {
            flag = false; minPos = -1; maxCnt = INFINITY;
            start = meetings[i][0];
            end = meetings[i][1];

            for(j = 0; j < n; j++) {
                if(maxCnt > cnt[j]) {
                    maxCnt = cnt[j];
                    minPos = j;
                }

                if(cnt[j] <= start) {
                    cnt[j] = end;
                    dCnt[j]++;
                    flag = true;
                    break;
                }
            }

            if(!flag) {
                cnt[minPos] += ((long long) 1 * (end - start));
                dCnt[minPos]++;
            }
        }

        maxPos = j = -1;
        for(i = 0; i < n; i++)
            if(maxPos < dCnt[i]) {
                maxPos = dCnt[i];
                j = i;
            }

        return j;
    }
};