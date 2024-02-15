
/**
 * Runtime: beats 71.43% of users with C
 * Memory: beats 71.43% of users with C
 * Daily problem (Streak 2)
*/

int comparator(const void *x, const void *y) {
    return *(int *)x - *(int *)y;
}

long long largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), comparator);

    int i;
    long long sum = 0, ret = -1;

    for(i = 0; i < numsSize; i++) {
        if(sum > nums[i])
            ret = sum + nums[i];
        sum += nums[i];
    }

    return ret;
}