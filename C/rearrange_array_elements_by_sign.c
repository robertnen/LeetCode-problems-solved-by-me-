/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Runtime: beats 97.50% of users with C
 * Memory: beats 67.50% of users with C
 * Daily problem
*/

int* rearrangeArray(int *nums, int numsSize, int *returnSize) {
    int *tmp = (int *) malloc(numsSize * sizeof(int));
    int i, pos = 0, neg = 0;

    *returnSize = numsSize;

    for(i = 0; i < numsSize; i++)
        if(nums[i] > 0) {tmp[(pos << 1)] = nums[i]; pos++;}
        else {tmp[(neg << 1) + 1] = nums[i]; neg++;}

    return tmp;
}