#include <stdbool.h>
#include <limits.h>

int myAtoi(char* s) {
    long ans = 0;
    int len = strlen(s), i = 0;
    bool flag = false;

    while(i < len && s[i] == ' ') i++;

    if(i < len && s[i] == '-') {flag = true; i++;}
    if(i < len && i && s[i] == '+' && s[i - 1] == '-') return 0;
    if(i < len && s[i] == '+') i++;

    while(i < len && ('0' <= s[i] && s[i] <= '9')) {
        printf("%c", s[i]);
        ans = ans * 10 + s[i] - '0';

        if(ans > INT_MAX && flag) return INT_MIN;
        else if(ans > INT_MAX) return INT_MAX;

        i++;
    }

    return flag ? -ans : ans;
}