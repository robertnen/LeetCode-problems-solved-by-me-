#include <bits/stdc++.h>

/**
 * Runtime: beats 19.57% of users with C++
 * Memory: beats 75.10% of users with C++
 * Daily problem (Streak 58)
*/

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::stack<char> sd;
        int n = num.size();

        for(char digit : num) {
            while(!sd.empty() && k > 0 && digit < sd.top()) {
                sd.pop(); k--;
            }

            sd.push(digit);
        }

        while(k > 0 && !sd.empty()) {sd.pop(); k--;}

        num = "";
        while(!sd.empty()) {
            num += sd.top();
            sd.pop();
        }

        n = num.size();

        for(int i = 0; i < n / 2; i++)
            std::swap(num[i], num[n - 1 - i]);

        while(num[0] == '0') num.erase(0, 1);

        if(num == "") num = "0";

        return num;
    }
};