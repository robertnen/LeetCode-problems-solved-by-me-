#include <cstring>
#include <iostream>

/**
 * Runtime: beats 31.42% of users with C++
 * Memory: beats 63.14% of users with C++
 * Daily problem (Streak 17)
*/

class Solution {
public:
    std::string maximumOddBinaryNumber(std::string s) {
        unsigned char n = s.size(), counter = 0;

        if(n == 1) return s;

        char *p = &s[0];
        while(*p != '\0') {
            if(*p == '1') counter++;
            p++;
        }

        memset(&s[0], '1', counter - 1);
        memset(&s[counter - 1], '0', n - counter);
        s[n - 1] = '1';

        return s;
    }
};