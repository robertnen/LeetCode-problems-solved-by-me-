/**
 * Runtime: beats 100% of users with C
 * Memory: beats 16.67% of users with C
 * Daily problem (Streak 30)
*/

int totalSums(int* nums, int size, int goal) {
    int left, right, sum, ans;

    left = right = sum = ans = 0;

    while(right < size) {
        sum += nums[right];

        while(sum > goal && left <= right) sum -= nums[left++];

        ans += right - left + 1;
        right++;
    }

    return ans;
}

int numSubarraysWithSum(int* nums, int numsSize, int goal) {
    return totalSums(nums, numsSize, goal) - totalSums(nums, numsSize, goal - 1);
}