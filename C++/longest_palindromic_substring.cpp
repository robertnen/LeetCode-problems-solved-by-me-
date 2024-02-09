#include <bits/stdc++.h>

class Solution {
public:
    std::string getPalin(std::string src, int start, int end) {
        int n = src.length();

        while(start >= 0 && end < n && src[start] == src[end]) {start--; end++;}
        return src.substr(start + 1, end - start - 1);
    }

    std::string longestPalindrome(std::string s) {
        if(s.length() == 1) return s;

        std::string result = s.substr(0, 1), odd, even;
        int i = 0, n = s.length();

        while(i < n - 1) {
            odd = this->getPalin(s, i, i);
            even = this->getPalin(s, i, i++ + 1);

            if(odd.length() > result.length()) result = odd;
            if(even.length() > result.length()) result = even;
        }
        return result;
    }
};