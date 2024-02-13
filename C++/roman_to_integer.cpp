#include <bits/stdc++.h>

/**
 * Runtime: beats 100% of users with C++
 * Memory: beats 35.58% of users with C++
*/

class Solution {
public:
    int romanToInt(std::string s) {
        int i = 0, len = s.length(), n = 0;

        while(s[i] == 'M' && i < len) {n += 1000; i++;}
        while(s[i] == 'D' && i < len) {n +=  500; i++;}
        while(s[i] == 'C' && i < len) {
            if(s[i + 1] == 'M') {n += 900; i += 2; continue;}
            if(s[i + 1] == 'D') {n += 400; i += 2; continue;}
            n += 100; i++;
        }
        while(s[i] == 'L' && i < len) {n +=   50; i++;}
        while(s[i] == 'X' && i < len) {
            if(s[i + 1] == 'C') {n +=  90; i += 2; continue;}
            if(s[i + 1] == 'L') {n +=  40; i += 2; continue;}
            n +=  10; i++;
        }
        while(s[i] == 'V' && i < len) {n +=    5; i++;}
        while(s[i] == 'I' && i < len) {
            if(s[i + 1] == 'X') {n +=   9; i += 2; continue;}
            if(s[i + 1] == 'V') {n +=   4; i += 2; continue;}
            n++; i++;
        }
        return n;
    }
};