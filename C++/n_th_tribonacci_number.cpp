#include <bits/stdc++.h>

/**
 * Runtime: beats 100% of users with C++
 * Memory: beats 81.41% of users with C++
 * Daily problem (Streak 71)
*/

class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1, t;

        if(!n) return 0;
        if(n <= 2) return 1;

        for(char i = 3; i <= n; i++) {
            t = a + b + c;
            a = b;
            b = c;
            c = t;
        }

        return c;
    }
};