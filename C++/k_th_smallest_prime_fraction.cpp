#include <bits/stdc++.h>

/**
 * Runtime: beats 96.73% of users with C++
 * Memory: beats 97.12% of users with C++
 * Daily problem (Streak 87)
*/

class Solution {
public:
    std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) {
        std::vector<int> ans;
        double start = 0, end = 1, mid, maxim;
        int n = arr.size(), pos, rest, rem, counter;

        while(start <= end) {
            mid = (start + end) / 2;

            pos = 1;
            rest = rem = counter = maxim = 0;

            for(int i = 0; i < n; i++) {
                while(pos < n && arr[i] >= arr[pos] * mid) pos++;

                rest += n - pos;

                if(pos < n && maxim < arr[i] * 1. / arr[pos]) {
                    maxim = arr[i] * 1. / arr[pos];
                    counter = i; rem = pos;
                }
            }

            if(rest == k) {
                ans = {arr[counter], arr[rem]};
                break;
            }

            if(rest > k) end = mid;
            else start = mid;
        }
        return ans;
    }
};