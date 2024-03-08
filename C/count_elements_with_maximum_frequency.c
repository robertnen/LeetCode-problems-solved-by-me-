/**
 * Runtime: beats 33.33% of users with C
 * Memory: beats 88.89% of users with C
 * Daily problem (Streak 24)
*/

int maxFrequencyElements(int* nums, int numsSize) {
    char freq[101] = {0}, maxim = -1, total = 0;

    for(int i = 0; i < numsSize; i++) freq[nums[i] - 1]++;
    for(int i = 0; i < 101; i++) {
        if(maxim < freq[i]) {
            total = maxim = freq[i];
            continue;
        }

        if(maxim == freq[i]) total += maxim;
    }

    return total;
}