#include <limits.h>

/**
 * Runtime: beats 100% of users with C
 * Memory: beats 89.33% of users with C
*/

int reverse(int x){
    int y = 0;

    while(x) {
        if(y > INT_MAX / 10 || y < INT_MIN / 10) return 0;

        y = y * 10 + x % 10;
        x /= 10;
    }

    return y;
}