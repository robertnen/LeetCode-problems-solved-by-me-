#include <bits/stdc++.h>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> nums3;
        int i, j, n, m;

        n = nums1.size(); m = nums2.size();
        i = j = 0;

        while(i < n && j < m) {
            if(nums1[i] < nums2[j]) nums3.push_back(nums1[i++]);
            else nums3.push_back(nums2[j++]);
        }

        while(i < n) nums3.push_back(nums1[i++]);
        while(j < m) nums3.push_back(nums2[j++]);

        n += m;
        return n % 2 ? nums3[n / 2] : ((double) nums3[n / 2 - 1] + nums3[n / 2]) / 2;
    }
};