from ast import List
from math import gcd

# Runtime: beats 93.75% of users with Python3
# Memory: beats 65.63% of users with Python3
# Daily problem (Streak 12)

class Solution:
    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        n = len(nums)

        if n == 1:
            return True
        if 1 in nums:
            return False

        nums = sorted(nums, reverse=True)
        for i in range(n - 1):
            for j in range(i + 1, n):
                d = gcd(nums[i], nums[j])
                if d > 1:
                    nums[j] *= nums[i] // d
                    break
            else:
                return False

        return True