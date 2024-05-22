from ast import List

# Runtime: beats 87.32% of users with Python3
# Memory: beats 41.59% of users with Python3
# Daily problem (Streak 99)

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        l = len(s)
        ans = []

        def bkt(idx, curr):
            if idx >= l:
                ans.append(curr.copy())

            for i in range(idx, l):
                st = s[idx : i + 1]
                if st == st[::-1]:
                    curr.append(st)
                    bkt(i + 1, curr)
                    curr.pop()

        bkt(0, [])

        return ans