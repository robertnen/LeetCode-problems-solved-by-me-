int searchInsert(int* nums, int numsSize, int target) {
    int left, right, mid;

    left = 0;
    right = numsSize;

    if(target > nums[right - 1]) return right;

    while(left <= right) {
        mid = left + (right - left) / 2;

        if(target == nums[mid]) return mid;

        if(target < nums[mid])  right = mid - 1;
        else left = mid + 1;
    }

    return left;
}