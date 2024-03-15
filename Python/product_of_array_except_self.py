from ast import List

# Runtime: beats 39.59% of users with Python3
# Memory: beats 19.76% of users with Python3
# Daily problem (Streak 31)

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        size = len(nums)
        before = size * [1]
        after = size * [1]

        for i in range(1, size):
            before[i] = before[i - 1] * nums[i - 1]

        for i in range(size - 2, -1, -1):
            after[i] = after[i + 1] * nums[i + 1]

        ans = [before[i] * after[i] for i in range(size)]

        return ans