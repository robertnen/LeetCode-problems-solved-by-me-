#include <string.h>

/**
 * Runtime: beats 100% of users with C
 * Memory: beats 82.64% of users with C
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    unsigned char len = 0, i = 0, n = strlen(strs[0]);
    for(;len < n; len++)
        for(i = 0; i < strsSize - 1; i++)
            if(strs[i][len] != strs[i + 1][len]) {
                strs[i][len] = '\0';
                return strs[i];
            }

    return strs[0];
}