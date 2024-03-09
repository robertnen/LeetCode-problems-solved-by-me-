/**
 * Runtime: beats 70.97% of users with C
 * Memory: beats 38.71% of users with C
 * Daily problem (Streak 25)
*/

int binarySearch(int x, int* v, int start, int end) {
    int mid;
    while(start <= end) {
        mid = (start + end) / 2;
        if(x == v[mid]) return mid;
        else if(x > v[mid]) start = mid + 1;
             else end = mid - 1;
    }

    return -1;
}

int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *a, *b, ans;

    if(nums1Size > nums2Size) {
        nums1Size ^= nums2Size;
        nums2Size ^= nums1Size;
        nums1Size ^= nums2Size;

        a = nums2;
        b = nums1;
    } else {
        a = nums1;
        b = nums2;
    }

    for(int i = 0; i < nums1Size; i++) {
        ans = binarySearch(a[i], b, 0, nums2Size - 1);
        if(ans != -1) return a[i];
    }

    return -1;
}